/*
 * 求 ax^2 + bx + c = 0 方程的根。a, b, c 由键盘输入，设 b^2 - 4ac > 0。
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, disc, x1, x2, p, q;
    scanf("%lf%lf%lf", &a, &b, &c);
    disc = b * b - 4 * a * c;
    p = -b / (2.0 * a);
    q = sqrt(disc) / (2.0 * a);
    x1 = p + q;
    x2 = p - q;
    printf("x1=%7.2f\nx2=%7.2f\n", x1, x2);
    return 0;
}