#include <stdio.h> // 这是编译预处理指令

int main()                      // 定义主函数
{                               // 函数开始
    int a, b, sum;              // 程序的声明部分
    a = 123;                    // 对变量 a 赋值
    b = 456;                    // 对变量 b 赋值
    sum = a + b;                // 计算 a + b 的值，结果保存到变量 c
    printf("sum is %d\n", sum); // 输出结果
    return 0;                   // 函数返回值为 0
} // 函数结束