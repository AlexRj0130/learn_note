/*
 * 例3.2
 *   计算存款利息。有 1000 元，想存一年。有 3 种方法可选：
 *    （1）活期，年利率为 r1；
 *    （2）一年定期，年利率为 r2；
 *    （3）存两次半年定期，年利率为 r3。
 *   请分别计算出一年后按 3 种方法所得到的本息和。
 */

#include <stdio.h>

int main()
{
    float p0 = 1000, r1 = 0.0036, r2 = 0.0225, r3 = 0.0198, p1, p2, p3;
    p1 = p0 * (1 + r1);
    p2 = p0 * (1 + r2);
    p3 = p0 * (1 + r3 / 2) * (1 + r3 / 2);
    printf("p1 = %f\np2 = %f\np3 = %f\n", p1, p2, p3);
    return 0;
}