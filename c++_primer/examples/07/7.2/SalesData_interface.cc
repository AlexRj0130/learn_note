#include "SalesData.h"

// 定义 SalesData 的非成员接口函数

istream &read(istream &is, SalesData &item)
{
    double price = 0;
    is >> item.bookNo
       >> item.units_sold
       >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const SalesData &item)
{
    os << item.isbn() << " "
       << item.units_sold << " "
       << item.revenue << " "
       << item.avg_price();
    return os;
}

SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;
}