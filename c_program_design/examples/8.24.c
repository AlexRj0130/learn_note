/*
 * 例8.24
 *   有两个整数 a 和 b，由用户输入 1, 2 或 3。
 *   如输入 1，程序就给出 a 和 b 中的大者；
 *   如输入 2，程序就给出 a 和 b 中的小者；
 *   如输入 3，程序就给出 a 和 b 的和。
 */

#include <stdio.h>

int main()
{
    void fun(int, int, int (* p)(int, int));
    int max(int, int);
    int min(int, int);
    int add(int, int);
    int a = 34, b = -21, n;
    printf("Please choose 1, 2 or 3:");
    scanf("%d", &n);
    switch (n)
    {
        case 1:
            fun(a, b, max);
            break;
        case 2:
            fun(a, b, min);
            break;
        case 3:
            fun(a, b, add);
            break;
        default:
            printf("Wrong choose result!!!\n");
    }
    return 0;
}

void fun(int a, int b, int (* p)(int, int))
{
    int result;
    result = (* p)(a, b);
    printf("%d\n", result);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int add(int a, int b)
{
    return a + b;
}