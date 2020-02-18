/*
 * 例9.9
 *   写一函数建立一个有 3 名学生数据的单向动态链表。
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct Student)
struct Student
{
    long num;
    float score;
    struct Student * next;
};  // 这个分号不能忘

struct Student * create(void)
{
    struct Student * head, * rear, * temp;
    long num;
    float score;
    scanf("%ld, %f", &num, &score);
    while(0 != num)
    {
        temp = malloc(LEN);
        temp->next = NULL;
        temp->num = num;
        temp->score = score;

        if (NULL == head)
        {
            head = rear = temp;
        }
        else
        {
           rear->next = temp;
           rear = temp; 
        }
        
        scanf("%ld, %f", &num, &score);
    }

    return head;
}

int main()
{
    struct Student * p, * read;
    p = read = create();
    while (NULL != read)
    {
        printf("%ld %5.1f\n", p->num, p->score);
        read = read->next;
    }
    return 0;
}