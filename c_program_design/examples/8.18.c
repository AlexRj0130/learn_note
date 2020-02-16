/*
 * 例8.18
 *   将字符串 a 复制为字符串 b，然后输出字符串 b。
 */

#include <stdio.h>

int main()
{
    char a[] = "I love China!";
    char b[20], c[20], * p1, * p2;
    int i;

    // 下标法存取字符串中的字符
    for (i = 0; *(a + i) != '\0'; i++)
    {
        *(b + i) = *(a + i);
    }
    *(b + i) = '\0';
    printf("string a is: %s\n", a);
    printf("string b is: ");
    for (i = 0; b[i] != '\0'; i++)
    {
        printf("%c", b[i]);
    }
    printf("\n");

    // 指针法存取字符串中的字符
    p1 = a;
    p2 = c;
    while(*p2++ = *p1++){}
    printf("string c is: ");
    p2 = c;
    while(*p2)
    {
        printf("%c", *p2++);
    }
    return 0;
}