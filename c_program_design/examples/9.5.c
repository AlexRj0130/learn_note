/*
 * 例9.5
 *   通过指向结构体变量的指针变量输出结构体变量中成员的信息。
 */

#include <stdio.h>
#include <string.h>

int main()
{
    struct Student
    {
        long num;
        char name[20];
        char sex;
        float score;
    };

    struct Student stu = {10101, "Li Lin", 'M', 89.5};
    struct Student * p;
    p = &stu;

    printf("No.:%ld\nname:%s\nsex:%c\nscore:%5.1f\n",
            stu.num, stu.name, stu.sex, stu.score);
    printf("\nNo.:%ld\nname:%s\nsex:%c\nscore:%5.1f\n",
            (* p).num, (* p).name, (* p).sex, (* p).score);
    return 0;
}