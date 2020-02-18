/*
 * 例8.29
 *   有一个指针数组，其元素分别指向一个整型数组的元素。
 *   用指向指针数据的指针变量，输出整型数组的各个元素的值。
 */

#include <stdio.h>

int main()
{
    int a[] = {1, 3, 5, 7, 9};
    int * num[] = {&a[0], &a[1], &a[2], &a[3], &a[4]};
    int **p, i;
    p = num;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", **p);
        p++;
    }
    printf("\n");
    return 0;
}