/*
 * 例8.3
 *   对输入的两个整数按大小顺序输出。
 *   要求用函数处理，而且用指针类型的数据作为函数参数。
 */

#include <stdio.h>

int main()
{
    void swap(int * p1, int * p2);
    int a, b;
    int * p1, * p2;
    printf("Please enter a and b:");
    scanf("%d, %d", &a, &b);
    p1 = &a;
    p2 = &b;
    if (a < b)
    {
        swap(p1, p2);
    }
    printf("max = %d, min = %d\n", a, b);
    return 0;
}

void swap(int * p1, int * p2)
{
    int temp;
    temp = * p1;
    * p1 = * p2;
    * p2 = temp;
}