/*
 * 例9.8
 *   建立一个链表，它由 3 个学生数据的结点组成。
 *   输出各结点中的数据。
 */

#include <stdio.h>

struct Student
{
    int num;
    float score;
    struct Student * next;
};  // 最后这个分号十分重要，不能落下

int main()
{
    struct Student a, b, c, * head, * p;
    a.num = 10101; a.score = 89.5;
    b.num = 10103; b.score = 90;
    c.num = 10107; c.score = 85;
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    p = head;

    while (p != NULL)
    {
        printf("%ld %5.1f\n", p->num, p->score);
        p = p->next;
    }
    return 0;
}