/*
 * 例8.23
 *   输入两个整数，然后让用户选择 1 或 2:
 *   选 1 时调用 max 函数，输出两者中的大数；
 *   选 2 时调用 min 函数，输出两者中的小数。
 */

#include <stdio.h>

int main()
{
    int max(int, int);
    int min(int, int);
    int (* p)(int, int);
    int a, b, c, n;
    printf("Please enter a and b:");
    scanf("%d, %d", &a, &b);
    printf("Please choose 1 or 2:");
    scanf("%d", &n);
    if (n == 1)
    {
        p = max;
    }
    else if (n == 2)
    {
        p = min;
    }
    c = (* p)(a, b);
    printf("a = %d, b = %d\n", a, b);
    if (n == 1)
    {
        printf("max = %d\n", c);
    }
    else if (n == 2)
    {
        printf("min = %d\n", c);
    }
    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
} 