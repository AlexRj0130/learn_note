/*
 * 例9.4
 *   有 n 个学生的信息（包括学号、姓名、成绩），
 *   要求按照成绩的高低顺序输出各学生的信息。
 */

#include <stdio.h>

struct Student
{
    int num;
    char name[20];
    float score;
};

int main()
{
    struct Student stu[5] = 
    {
        {10101, "Zhang", 78},
        {10103, "Wang", 98.5},
        {10106, "Li", 86},
        {10108, "Ling", 73.5},
        {10110, "Sun", 100}
    };  // 在定义结构体数组时进行初始化。
    struct Student temp;
    const int n = 5;
    int i, j, k;
    printf("The order is:\n");
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (stu[j].score > stu[k].score)
            {
                temp = stu[k];
                stu[k] = stu[i];
                stu[i] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%6d %8s %6.2f\n", stu[i].num, stu[i].name, stu[i].score);
    }
    printf("\n");
    return 0;
}