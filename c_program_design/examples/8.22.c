/*
 * 例8.22
 *   用函数求整数 a 和 b 中的大者。
 */

#include <stdio.h>

int main()
{
    int max(int, int);
    int (* p)(int, int);
    int a, b, c;
    p = max;

    printf("Please enter a and b:");
    scanf("%d, %d", &a, &b);
    c = (* p)(a, b);
    printf("a = %d\nb = %d\nmax = %d\n", a, b, c);
    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}