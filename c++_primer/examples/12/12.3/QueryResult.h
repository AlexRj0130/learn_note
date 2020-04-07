#include <iostream>
#include <memory>


std::ostream & print(std::ostream &, const QueryResult &);

class QueryResult
{
friend std::ostream & print(std::ostream &, const QueryResult &);
public:
    QueryResult(std::string s, 
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) { }
private:
    std::string sought;  // 要查询的单词
    std::shared_ptr<std::set<line_no>> lines;  // 出现的行号
    std::shared_ptr<std::vector<std::string>> file;  // 输入文件
};