/*
 * 例4.3：
 *   输入 3 个数 a, b, c，要求按从小到大的顺序输出。
 */

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, t;
    scanf("%f,%f,%f", &a, &b, &c);
    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }
    if (a > c)
    {
        t = a;
        a = c;
        c = t;
    }
    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    }
    printf("%5.2f, %5.2f, %5.2f", a, b, c);
    return 0;
}