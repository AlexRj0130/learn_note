/*
 * 例8.7
 *   通过指针变量输出整型数组 a 的 10 个元素。
 */

#include <stdio.h>

int main()
{
    int * p, i, a[10];
    p = a;
    printf("Please enter 10 integer numbers:");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", p++);
    }

    // 通过指针输出数组中的元素
    // for (i = 0; i < 10; i++, p++)  // 这条语句不对，因为 p 的值已经不是数组元素的首地址
    for (i = 0, p = a; i < 10; i++, p++)  // 这条语句正确
    {
        printf("%d ", * p);
    }
    printf("\n");
    return 0;
}