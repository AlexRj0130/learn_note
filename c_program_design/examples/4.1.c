/*
 * 例4.1：求解 ax^2 + bx + c = 0 方程的根。由键盘输入 a, b, c。
 * 假设 a, b, c 的值任意，并不保证 b^2 - 4ac >= 0。
 * 需要在程序中进行判别，如果 b^2 - 4ac >= 0，就计算并输出方程的两个实根；
 * 否则，就输入“方程无实根”的信息。
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, disc, x1, x2, p, q;
    scanf("%lf%lf%lf", &a, &b, &c);
    disc = b * b - 4 * a * c;
    if (disc < 0)
        printf("This equation hasn't real roots\n"); // 如果 b^2 - 4ac < 0
    else
    {
        p = -b / (2.0 * a);
        q = sqrt(disc) / (2.0 * a);
        x1 = p + q;
        x2 = p - q;
        printf("real roots:\nx1 = %7.2f\nx2 = %7.2f\n", x1, x2);
    }
    
    return 0;
}