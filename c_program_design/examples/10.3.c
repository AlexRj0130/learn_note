/*
 * 例10.3
 *   从文件中读入若干个字符串，对它们按字母大小的顺序排序，
 * 然后把排好序的字符串送到磁盘文件中保存。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const int n = 3;
    char str[n][10], temp[10];
    FILE *pIn;
    if (NULL == (pIn = fopen("./source.dat", "r")))
    {
        printf("Can not open input file!\n");
        exit(0);
    }

    for (int i = 0; NULL != fgets(str[i], 10, pIn); ++i)
    {
        printf("%s\n", str[i]);
    }
    fclose(pIn);

    for (int i = 0; i < n - 1; ++i)
    {
        int k = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (strcmp(str[k], str[j]) > 0)
            {
                k = j;
            }
        }
        if (k != i)
        {
            strcpy(temp, str[i]);
            strcpy(str[i], str[k]);
            strcpy(str[k], temp);
        }
    }

    FILE *pOut;
    if (NULL == (pOut = fopen("./target.dat", "w")))
    {
        printf("Can not open output file!\n");
        exit(0);
    }

    printf("\nThe new sequence:\n");
    for (int i = 0; i < n; i++)
    {
        fputs(str[i], pOut);
        fputs("\n", pOut);
        printf("%s\n", str[i]);
    }
    fclose(pOut);
    return 0;
}

