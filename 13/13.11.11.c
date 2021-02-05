#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char fileName[255];
    char targetStr[255];
    char buf[256];
    int line = 0;
    scanf("%s %s", fileName, targetStr);
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("open %s failed", argv[1]);
        exit(EXIT_FAILURE);
    }
    // 指明读入字符的最大数量为256，fgets将读入255个字符（留一个字节放字符'\0'）或者读到遇到的第一个换行符为止。
    // fgets读到一个换行符，会把它放到字符串的末尾。
    // puts函数会在字符串的末尾添加换行符，而fputs函数不会在字符串末尾添加换行符。
    while (fgets(buf, 256, fp) != NULL) {
        line++;
        if (strstr(buf, targetStr) != NULL)
            printf("%d", line);
    }
    fclose(fp);
    return 0;
}
