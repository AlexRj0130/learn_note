/*
 * 例7.8
 *   Hanoi（汉诺）塔问题。
 *   这是一个古典的数学问题，是一个用递归方法解题的典型例子。
 *   问题是这样的：
 *   古代有一个梵塔，塔内有3个座，分别是 A, B, C，
 *   开始时 A 座上有 64 个盘子，盘子的大小不等，大的在下，小的在上。
 *   有一个老和尚想把这 64 个盘子从 A 座移到 C 座，
 *   但规定每次只允许移动一个盘子，且移动过程中 3 个座都需要保持大盘子在下，小盘子在上。
 *   在移动过程中可以利用 B 座。
 *   要求编程序输出移动盘子的步骤。
 */

#include <stdio.h>

int main()
{
    void hanoi(int n, char one, char two, char three);
    int m;
    printf("Please input the number of diskes:");
    scanf("%d", &m);
    printf("The step to move %d diskes:\n", m);
    hanoi(m, 'A', 'B', 'C');
    return 0;
}

// 将 n 个盘子从 one 座移动到 three 座（借助 two 座）
void hanoi(int n, char one, char two, char three)
{
    void move(char x, char y);
    if (n == 1)
    {
        move(one, three);
        return;
    }
    
    // 第 n 个盘子最大，并且位于某个塔的最底层，
    // 所以在移动 n - 1 个盘子的时候，不会破坏大盘子在下面，小盘子在上面的要求。
    hanoi(n - 1, one, three, two);
    move(one, three);
    hanoi(n - 1, two, one, three);
    return;
}

// 将一个盘子从 x 座移动到 y 座
void move(char x, char y)
{
    printf("%c --> %c\n", x, y);
}