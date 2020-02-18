/*
 * 例7.4
 *   输入两个实数，用一个函数求它们的和。
 */

#include <stdio.h>

int main()
{
    float add(float x, float y);  // 对 add 函数进行声明
    float a, b, c;
    printf("Please enter a and b:");
    scanf("%f, %f", &a, &b);
    c = add(a, b);
    printf("sum is %f\n", c);
    return 0;
}

float add(float x, float y)  // 定义 add 函数
{
    return x + y;
}