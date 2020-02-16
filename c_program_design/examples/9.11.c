/*
 * 例9.11
 *   有若干个人员的数据，其中有学生和教师。
 *   学生的数据中包括：姓名、号码、性别、职业、班级。
 *   教师的数据中包括：姓名、号码、性别、职业、职务。
 *   要求用同一个表格来处理。
 */

#include <stdio.h>

struct Person
{
    char name[10];
    int num;
    char sex;
    char job;
    union 
    {
        int clas;
        char position[10];
    } category;
};

int main()
{
    struct Person person[2];
    // 数据输入
    for (int i = 0; i < 2; ++i)
    {
        printf("Please enter the data of person:\n");
        scanf("%d %s %c %c", &person[i].num, person[i].name, &person[i].sex, &person[i].job);
        if (person[i].job == 's')
        {
            scanf("%d", &person[i].category.clas);  // 这里用了取地址符
        }
        else if (person[i].job == 't')
        {
            scanf("%s", person[i].category.position);  // 这里没有用取地址符
        }
        else 
        {
            printf("Wrong input!\n");
        }
    }

    // 结果输出
    printf("\nNo.    name     sex   job   class/position\n");
    for (int i = 0; i < 2; i++)
    {
        if (person[i].job == 's')
        {
            printf("%-6d%-10s%-4c%-4c%-10d\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].category.clas);
        }
        else
        {
            printf("%-6d%-10s%-4c%-4c%-10s\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].category.position);
        }
    }

    return 0;
}