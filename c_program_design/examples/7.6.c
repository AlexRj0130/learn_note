/*
 * 例7.6 
 *   有5个学生坐在一起，
 *   第5个学生比第4个学生大2岁；
 *   第4个学生比第3个学生大2岁；
 *   第3个学生比第2个学生大2岁；
 *   第2个学生比第1个学生大2岁；
 *   第1个学生10岁。
 *   问第5个学生多少岁？
 * 
 * 思路：
 *   age(n) = 10              (n = 1)
 *   age(n) = age(n - 1) + 2  (n > 1)
 */

#include <stdio.h>

int main()
{
    int age(int n);
    printf("NO.5, age: %d\n", age(5));
}

int age(int n)
{
    if (1 == n)
        return 10;
    return age(n - 1) + 2;
}

