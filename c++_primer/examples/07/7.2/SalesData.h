#include <iostream>

// 使用 class 关键字声明类
// 通过访问说明符指定访问级别
// 指定友元函数
class SalesData  
{
// 友元声明
friend SalesData add(const SalesData &, const SalesData &);
friend std::ostream &print(std::ostream &, const SalesData &);
friend std::istream &read(std::istream &, SalesData &);

public:
    SalesData() = default;  // 显式要求编译器按照默认规则生成默认构造函数
    SalesData(const std::string &s) : bookNo(s) { }  // 构造函数初始值列表
    SalesData(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { }
    SalesData(std::istream &);

    std::string isbn() const { return bookNo; }
    SalesData &combine(const SalesData &);
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;  // 类内初始值
    double revenue = 0.0;
};

// 声明非成员的接口函数
SalesData add(const SalesData &, const SalesData &);
std::ostream &print(std::ostream &, const SalesData &);
std::istream &read(std::istream &, SalesData &);
