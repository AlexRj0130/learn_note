/*
 * 例4.7
 *   用 switch 语句处理菜单命令。
 *   在许多应用程序中，用菜单对流程进行控制。
 *   例如从键盘输入一个'A'或'a'，就会执行 A 操作；输入一个'B'或'b'，就会执行 B 操作。
 *   编程思路如下。
 */

#include <stdio.h>

int main()
{
    void action1(int, int), action2(int, int);
    char ch;
    int a = 15, b = 23;
    ch = getchar();
    switch (ch)
    {
    case 'a':
    case 'A':
        action1(a, b);
        break;
    case 'b':
    case 'B':
        action2(a, b);
        break;
    default:
        putchar('\a'); // 如果输入其他字符，发出警告
    }
    return 0;
}