#include <iostream>

struct SalesData
{
    SalesData() = default;  // 显式要求编译器按照默认规则生成默认构造函数
    SalesData(const std::string &s) : bookNo(s) { }  // 构造函数初始值列表
    SalesData(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { }
    SalesData(std::istream &);

    std::string isbn() const { return bookNo; }
    SalesData &combine(const SalesData &);
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;  // 类内初始值
    double revenue = 0.0;
};

// SalesData 的非成员接口函数
SalesData add(const SalesData &, const SalesData &);
std::ostream &print(std::ostream &, const SalesData &);
std::istream &read(std::istream &, SalesData &);