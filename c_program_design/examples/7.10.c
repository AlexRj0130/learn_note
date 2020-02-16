/*
 * 例7.10
 *   有一个一维数组score，内放 10 个学生成绩，求平均成绩。
 */

#include <stdio.h>

int main()
{
    float average(float array[10]);
    float score[10], aver;
    int i;
    printf("Please input 10 scores:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%f", &score[i]);
    }
    printf("\n");
    aver = average(score);
    printf("average score is %5.2f\n", aver);
    return 0;
}

float average(float array[10])
{
    int i = 0;
    float aver, sum = array[0];
    for (i = 1; i < 10; i++)
    {
        sum += array[i];
    }
    aver = sum / 10;
    return aver;
}