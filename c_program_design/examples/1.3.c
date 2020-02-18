#include <stdio.h>

int main()                   // 定义主函数
{                            // 主函数体开始
    int max(int x, int y);   // 声明 max 函数
    int a, b, c;             // 定义变量 a, b, c
    scanf("%d,%d", &a, &b);  // 输入变量 a 和 b 的值
    c = max(a, b);           // 调用 max 函数，将函数的结果赋值给变量 c
    printf("max = %d\n", c); // 输出 c 的值
    return 0;                // 返回函数值为 0
} // 主函数体结束

// 求两个整数中的较大者
int max(int x, int y) // 定义 max 函数，函数值为整型，形式参数 x 和 y 为整型
{
    int z;     // 声明变量 z
    if (x > y) // 如果 x 大于 y，将 x 的值赋值给变量 z
    {
        z = x;
    }
    else // 否则，将 y 的值赋值给变量 z
    {
        z = y;
    }
    return z; // 返回结果
}