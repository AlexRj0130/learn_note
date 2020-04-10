

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec & operator=(const StrVec&);
    ~StrVec();
public:
    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string * begin() const { return elements; }
    std::string * end() const { return first_free; }
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }  // 保证 StrVec 至少有容纳一个新元素的空间。如果没有空间添加新元素，该函数会调用 reallocate 来分配更多内存
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);  // 分配内存，并拷贝一个给定范围中的元素
    void free();  // 销毁构造的元素并释放内存
    void reallocate();  // 在内存用完时为 StrVec 分配新内存
private:
    std::string *elements;  // 指向分配的内存中的首元素
    std::string *first_free;  // 指向最后一个实际元素之后的位置
    std::string *cap;  // 指向分配的内存末尾之后的位置
};