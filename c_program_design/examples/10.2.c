/*
 * 例10.2
 *   将一个磁盘文件中的信息复制到另一个磁盘文件中。
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pIn, *pOut;
    char ch, inFileName[10], outFileName[10];
    
    printf("输入读入文件的名字：");
    scanf("%s", inFileName);
    printf("输入输出文件的名字：");
    scanf("%s", outFileName);

    if (NULL == (pIn = fopen(inFileName, "r")))
    {
        printf("无法打开输入文件\n");
        exit(0);
    }
    if (NULL == (pOut = fopen(outFileName, "w")))
    {
        printf("无法打开输出文件\n");
        exit(0);
    }

    while(!feof(pIn))  // 判断是否已经读到文件末尾的结束标志
    {
        ch = fgetc(pIn);
        fputc(ch, pOut);
        putchar(ch);
    }
    putchar('\n');
    fclose(pIn);
    fclose(pOut);

    return 0;
}