/*
 * 例9.6
 *   有 3 个学生的信息，放在结构体数组中。
 *   要求输出全部学生的信息。
 */

#include <stdio.h>

struct Student
{
    int num;
    char name[20];
    char sex;
    int age;
};

int main()
{
    struct Student * p;
    struct Student stu[3] = 
    {
        {10101, "Li Lin", 'M', 18},
        {10102, "Zhang Fang", 'M', 19},
        {10104, "Wang Min", 'F', 20},
    };
    for (p = stu; p < stu + 3; p++)
    {
        printf("%5d %-20s %2c %4d\n", p->num, p->name, p->sex, p->age);
    }
}