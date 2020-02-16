/*
 * 例8.6
 *   由一个整型数组 a，有10个元素，要求输出数组中的全部元素。
 */

#include <stdio.h>

int main()
{
    int a[10];
    int i;
    printf("Please enter 10 integer numbers:");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    // 使用下标法
    for (i = 0; i < 10; i++)
    {
        printf("%d", a[i]);  // 数组元素用数组名和下标表示
    }
    printf("\n");

    // 通过数组名计算数组元素地址
    for (i = 0; i < 10; i++)
    {
        printf("%d", *(a+i));  // 通过数组名和元素序号计算元素地址
    }
    printf("\n");

    // 用指针变量指向数组元素
    int * p;
    for (p = a; p < (a + 10); p++)
    {
        printf("%d", * p);  // 用指针指向当前的数组元素
    }
    printf("\n");

    return 0;
}