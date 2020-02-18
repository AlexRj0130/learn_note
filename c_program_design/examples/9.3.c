/*
 * 例9.3
 *   有 3 个候选人，每个选民只能投票选一人。
 *   要求编一个统计选票的程序，先后输入被选人的名字，最后输出各人得票结果。
 */

#include <stdio.h>
#include <string.h>

struct Person
{
    char name[20];
    int count;
};

int main()
{
    int i, j;
    char leader_name[20];
    struct Person leader[3] = {{"Li", 0}, {"Zhang", 0}, {"Sun", 0}};
    for (i = 1; i <= 10; i++)
    {
        scanf("%s", leader_name);
        for (j = 0; j < 3; j++)
        {
            if (strcmp(leader_name, leader[j].name) == 0)
            {
                leader[j].count++;
            }
        }
    }
    printf("\nResult:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%5s:%d\n", leader[i].name, leader[i].count);
    }
    return 0;
}