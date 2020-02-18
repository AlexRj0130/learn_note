/*
 * 例8.8
 *   将数组 a 中的 n 个整数按相反顺序存放。
 */

#include <stdio.h>

int main()
{
    // void inv(int x[], int n);
    void inv(int * x, int n);  // 与上一行的数组形参等价
    int i, a[10] = {3, 7, 9, 11, 0, 6, 7, 5, 4, 2};
    printf("The original array:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    inv(a, 10);
    printf("The array has been inverted:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

// void inv(int x[], int n)
void inv(int * x, int n)
{
    int temp, i, j, m = (n - 1) / 2;
    for (i = 0; i <= m; i++)
    {
        j = n - 1 - i;
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
    }
}