/*
 * 例7.2
 *   输入两个整数，要求输出其中较大者。要求用函数来找到大数。
 */

#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int a, b, c;
    printf("please enter two integer numbers:");
    scanf("%d,%d", &a, &b);
    c = max(a, b);
    printf("max is %d\n", c);
    return 0;
}