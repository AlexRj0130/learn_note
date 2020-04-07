#include <memory>

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
public:
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    std::string & front();
    std::string & back();
private:
    void check(size_type i, const std::string &msg) const;
private:
    std::shared_ptr<std::vector<std::string>> data;
};