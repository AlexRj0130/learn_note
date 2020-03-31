#include "SalesData.h"


// 在类的外部定义构造函数
SalesData::SalesData(std::istream &is)
{
    read(is, *this);  // 注意这里可以直接把 *this 对象传入，具体原因见 《C++ 对象模型》
}


// 定义 SalesData 的成员函数

double SalesData::avg_price() const 
{
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}

SalesData & SalesData::combine(const SalesData &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}