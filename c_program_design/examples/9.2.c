/*
 * 例9.2
 *   输入两个学生的学号、姓名和成绩，输出成绩较高的学生的学号、姓名和成绩。
 */

#include <stdio.h>

int main()
{
    struct Student
    {
        int num;
        char name[20];
        float score;
    };
    struct Student student1, student2, student3;
    scanf("%d%s%f", &student1.num, student1.name, &student1.score);  // 注意 name 是数组名，本身代表的就是地址。
    scanf("%d%s%f", &student2.num, student2.name, &student2.score);

    if (student1.score > student2.score)
    {
        student3 = student1;
    }
    else if (student2.score > student1.score)
    {
        student3 = student2;
    }
    else
    {
        printf("The score of the two student are equal!!!\n");
        return 0;
    }
    printf("The higher score is:\n");
    printf("%d\t%s\t%6.2f\n", student3.num, student3.name, student3.score);
    return 0;
}