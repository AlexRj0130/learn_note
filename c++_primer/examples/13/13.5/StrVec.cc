#include "StrVec.h"


StrVec::StrVec(const StrVec & s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec & StrVec::operator=(const StrVec & rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const std::string & s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)  // 分配内存，并拷贝一个给定范围中的元素
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy{b, e, data}};
}

void StrVec::free()  // 销毁构造的元素并释放内存
{
    if (elements)
    {
        for (auto p = first_free; p != elements; /*空*/ )
        {
            alloc.destory(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()  // 在内存用完时为 StrVec 分配新内存
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));  // 注意理解这里
    }
    // 先构造完再释放，确保即使发生异常，当前对象仍处于有效状态
    free();
    elements = newdata;
    first_free = dest;
    cap = newdata + newcapacity;
}