/*
 * 例7.5
 *   输入4个整数，找出其中最大的数。用函数的嵌套调用来处理。
 */

#include <stdio.h>

int main()
{
    int max4(int a, int b, int c, int d);
    int a, b, c, d, max;
    printf("Please enter 4 interger numbers:");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    max = max4(a, b, c, d);
    printf("max = %d\n", max);
    return 0;
}

int max4(int a, int b, int c, int d)
{
    int max(int a, int b);
    return max(a, max(b, max(c, d)));
}

int max(int a, int b)
{
    return a > b ? : a, b;
}