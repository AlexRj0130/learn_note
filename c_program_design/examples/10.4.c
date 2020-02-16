/*
 * 例10.4
 *   从文件输入 10 个学生的有关数据，然后把它们转存到另一个磁盘文件上去。
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct
{
    char name[10];
    char addr[15];
    int num;
    int age;
} Student;

void save(Student stu[SIZE])
{
    FILE *pf;
    if (NULL == (pf = fopen("target.dat", "wb")))  // 二进制写出
    {
        printf("can not open output file!\n");
        return;
    }

    for (int i = 0; i < SIZE; ++i)
    {
        if (1 != fwrite(&stu[i], sizeof(Student), 1, pf))
        {
            printf("file write error!\n");
        }
    }

    fclose(pf);
}

void read(Student stu[SIZE])
{
    FILE *pf;
    if (NULL == (pf = fopen("source.dat", "WB")))  // 二进制读入
    {
        printf("can not open input file!\n");
        return;
    }

    for (int i = 0; i < SIZE; ++i)
    {
        if (1 != fread(&stu[i], sizeof(Student), 1, pf))
        {
            printf("file read error!\n");
        }
    }

    fclose(pf);
}

int main()
{
    Student stu[SIZE];
    read(stu);
    write(stu);
    return 0;
}