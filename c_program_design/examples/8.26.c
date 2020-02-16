/*
 * 例8.25
 *   有 a 个学生，每个学生有 b 门课程的成绩。
 *   找出其中有不及格的课程的学生及其学生号。
 *   用指针函数来实现。
 */

#include <stdio.h>

int main()
{
    float score[][4] = {{60, 70, 80, 90}, {56, 89, 67, 88}, {34, 78, 90, 66}};
    float * search(float (* pointer)[4]);
    float * p;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        p = search(score + i);
        if (p == *(score + i))
        {
            printf("No. %d score:", i);
            for (j = 0; j < 4; j++)
            {
                printf("%5.2f\t", * (p + j));
            }
            printf("\n");
        }
    }
    return 0;
}

float * search(float (* pointer)[4])
{
    int i;
    float * pt = NULL;
    for (i = 0; i < 4; i++)
    {
        if (*(*pointer + i) < 60)
        {
            pt = *pointer;
        }
    }
    return pt;
}