/*
 * 例7.7
 *   用递归方法求 n!。
 * 
 * 思路：
 *   n! = 1             (n = 0, 1)
 *   n! = n * (n - 1)!  (n > 1)
 */

int main()
{
    int fac(int n);
    int n;
    int y;
    printf("input an integer number:");
    scanf("%d", &n);
    y = fac(n);
    printf("%d! = %d\n", n, y);
    return 0;
}

int fac(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * fac(n - 1);
}