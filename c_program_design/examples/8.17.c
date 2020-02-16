/*
 * 例8.17
 *   通过字符指针变量输出一个字符串。
 */

#include <stdio.h>

int main()
{
    char * string = "I love China!";  // 在静态存储区开辟字符数组存储该字符串常量，但该字符数组没有名字，不能通过数组名来引用，只能通过指针变量引用。
    printf("%s\n", string);
    return 0;
}