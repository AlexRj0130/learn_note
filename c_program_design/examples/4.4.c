/*
 * 例4.4
 *   输入一个字符，判断它是否为大写字母，如果是，将它转换为小写字母；如果不是，不转换。
 * 然后输出最后得到的字符。
 */

#include <stdio.h>

int main()
{
    char ch;
    scanf("%c", &ch);
    ch = (ch >= 'A' && ch <= 'Z') ? (ch + 32) : ch;
    printf("%c\n", ch);
    return 0;
}