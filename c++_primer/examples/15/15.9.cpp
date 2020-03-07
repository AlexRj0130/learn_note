/*
 例15.9：
   实现一个文本查询程序，需要支持以下操作
     单词查询：用于得到匹配某个给定 string 的所有行；
     逻辑非查询：使用 ~ 运算符得到不匹配查询条件的所有行；
     逻辑或查询：使用 | 运算符返回匹配两个条件中任意一个的行；
     逻辑与查询：使用 & 运算符返回匹配全部两个条件的行。
 */

#include <iostream>

class QueryResult
{
    friend std::ostream & print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines<p>, file(f) {}
private:
    std::string sought;  // 查询的单词
    std::shared_ptr<std::set<line_no>> lines;  // 查询的单词出现的行号
    std::shared_ptr<std:vector<std::string>> file;  // 输入文件
};

std::ostream & print(ostream & os, const QueryResult & qr)
{
    // 如果找到了单词，打印出现次数和所有出现的位置
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    // 打印单词出现的每一行
    for (auto num : *qr.lines)  // 对 set 中每个单词
    {
        // 避免行号从 0 开始给用户带来的困惑
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    }
    return os;
}

class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> file; // 输入文件
    // 每个单词到它所在的行号的集合的映射
    std::map<std::string, 
             std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream & is): file(new vector<string>)
{
    string text;
    while (getline(is, text))  // 对读入文件的每一行
    {
        file->push_back(text); // 保存此行文本
        int n = file->size() - 1;  // 当前行号
        istringstream line(text);  // 将文本分解为单词
        string word;
        while (line >> word)  // 对文本行的每个单词
        {
            auto & lines = wm[word];  // lines 是一个 shared_ptr
            if (!lines)
            {
                lines.reset(new set<line_no>);  // 分配一个新的 set
            }
            lines->insert(n);  // 将此行号插入 set 中
        }
    }
};

QueryResult
TextQuery::query(const std::string & sought) const
{
    // 如果未找到 sought，我们将返回一个指向此 set 的指针
    static std::shared_ptr<set<line_no>> nodata(new set<line_no>);
    // 使用 find 而不是下标运算符来查找单词，避免将单词添加到 wm 中
    auto loc = wm.find(sought);
    if (loc == wm.end())
    {
        return QueryResult(sought, nodata, file);
    }
    else
    {
        return QueryResult(sought, loc->second, file);
    }
};

class Query
{
    // 这些运算符需要访问接受 shared_ptr 的构造函数，而该函数是私有的
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    Query(const std::string &)  // 构建一个新的 WordQuery
    // 接口函数：调用对应的 QueryBase 操作
    QueryResult eval(const TextQuery & t) const
    {
        return q->eval(t);
    }
    std::string rep() const
    {
        return q->rep();
    }
private:
    Query(std::shared_ptr<QueryBase> query): q(query) { }
    std::shared_ptr<QueryBase> q;
};

std::ostream &
operator<<(std::ostream & os, const Query & query)
{
    // Query::rep 通过它的 QueryBase 指针对 rep() 进行了虚调用
    return os << query.rep();
}

class QueryBase
{
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~QueryBase() = default;
private:
    // eval 返回与当前 Query 匹配的 QueryResult
    virtual QueryResult eval(const TextQuery &) const = 0;
    // rep 是表示查询的一个 string
    virtual std::string rep() const = 0;
};

class WordQuery: public QueryBase
{
    friend class Query;

    WordQuery(const std::string & s): query_word(s) { }
    QueryResult eval(const TextQuery & t) const
    {
        return t.query(query_word);
    }
    std::string rep() const
    {
        return query_word;
    }
    std::string query_word;
};

class NotQuery: public QueryBase
{
    friend Query operator~(const Query &);
    
    NotQuery(const Query & q): query(q) { }
    std::string rep() const
    {
        return "~(" + query.rep() + ")";
    }
};

inline Query operator~(const Query & operand)
{
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

QueryResult
NotQuery::eval(const TextQuery & text) const
{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        if (beg == end || *beg != n)
        {
            ret_lines->insert(n);
        }
        else if (beg != end)
        {
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}


class BinaryQuery: public QueryBase
{
protected:
    BinaryQuery(const Query & l, const Query & r, std::string s):
        lhs(l), rhs(r), opSym(s) { }
    // 抽象类：BinaryQuery 不定义 eval
    std::string rep() const 
    {
        return "(" + lhs.rep() + " "
                   + opSym + " "
                   + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};


class AndQuery: public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query & left, const Query & right):
        BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query & lhs, const Query & rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}


QueryResult
AndQuery::eval(const TextQuery & text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(),
                     right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery: public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query & left, const Query & right):
        BinaryQuery(left, right, "|") { }
    QueryResult eval(cost TextQuery &) const;
}

inline Query operator|(const Query & lhs, const Query & rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

QueryResult
OrQuery::eval(const TextQuery & text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

int main()
{
    Query q = Query("fiery") & Query("bird") | Query("wind");

    return 0;
}