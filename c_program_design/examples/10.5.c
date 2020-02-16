/*
 * 例10.5
 *   有一个磁盘文件，内有一些信息。
 *   要求第 1 次将它的内容显示在屏幕上，第 2 次把它复制到另一文件中。
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pIn, *pOut;
    if (NULL == (pIn = fopen("source.dat", "r")))
    {
        printf("Open source data file failed!\n");
        exit(0);
    }
    if (NULL == (pOut = fopen("target.dat", "w")))
    {
        printf("Open target data file faield!\n");
        exit(0);
    }

    while(!feof(pIn))
    {
        putchar(getc(pIn));  // 逐个读入字符并输出到屏幕
    }
    putchar('\n');

    rewind(pIn);  // 使文件位置标记返回到文件头
    while(!feof(pIn))
    {
        putc(getc(pIn), pOut);  // 逐个读入字符并输出到文件
    }
    putc('\n', pOut);

    fclose(pIn);
    fclose(pOut);

    return 0;
}