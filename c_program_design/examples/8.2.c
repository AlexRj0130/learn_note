/*
 * 例8.2
 *   输入 a 和 b 两个整数，按先大后小的顺序输入 a 和 b。
 */

#include <stdio.h>

int main()
{
    int * p1, * p2, a, b;
    printf("Please enter two integer numbers:");
    scanf("%d, %d", &a, &b);
    p1 = &a;
    p2 = &b;
    if (a < b)  // 不交换整型变量的值，而是交换两个指针变量的值
    {
        p1 = &b;
        p2 = &a;
    }
    printf("a = %d, b = %d\n", a, b);
    printf("max = %d, min = %d\n", *p1, *p2);
    return 0;
}