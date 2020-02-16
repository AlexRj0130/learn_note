/*
 * 例10.6
 *   在磁盘上存有 10 个学生的数据。
 *   要求将第 1, 3, 5, 7, 9 个学生数据输入计算机，并在屏幕上显示出来。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[10];
    char addr[15];
    int num;
    int age;
} Student;

void read(Student stu[5])
{
    FILE *pf;
    if (NULL == (pf = fopen("source.dat", "rb")))
    {
        printf("can not open source file\n");
        return;
    }

    for (int i = 0, j = 0; i < 10; i += 2, ++j)
    {
        fseek(pf, i * sizeof(Student), SEEK_SET);  // 移动文件位置标记
        fread(&stu[j], sizeof(Student), 1, pf);  // 读取一个数据块到结构体变量
    }

    fclose(pf);
}

void print(Student stu[5])
{
    for (int i = 0; i < 5; ++i)
    {
        printf("%-10s %4d %4d %-15s\n", stu[i].name, stu[i].num, stu[i].age, stu[i].addr);
    }
}

int main()
{
    Student stu[5];
    read(stu);
    print(stu);
    return 0;
}
