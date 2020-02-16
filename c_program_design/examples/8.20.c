/*
 * 例8.20
 *   用函数调用实现字符串的复制。
 */

#include <stdio.h>

int main()
{
    void copy_string(char from[], char to[]);
    char a[] = "I am a teacher.";
    char b[] = "You are a student.";
    printf("string a = %s\nstring b = %s\n", a, b);
    printf("copy string a to string b:\n");
    copy_string(a, b);
    printf("\nstring a = %s\nstring b = %s\n", a, b);
    return 0;
}

void copy_string(char from[], char to[])
{
    char * p1 = from, * p2 = to;
    while(*p2++ = *p1++);  // 这句话需要仔细理解
}