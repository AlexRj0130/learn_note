/*
 * 例5.2
 *   求 1 + 2 + 3 + ... + 100。
 */

#include <stdio.h>

int main()
{
    int i = 1, sum = 0;
    do
    {
        sum += 1;
        i++;
    } while (i <= 100);
    printf("sum = %d\n", sum);
    return 0;
}