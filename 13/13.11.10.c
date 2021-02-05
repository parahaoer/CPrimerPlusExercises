#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int pos = 0;
    char fileName[256];
    char line[256];
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("打开文件%s错误", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((scanf("%d", &pos) > 0) && pos > 0) {
        fseek(fp, pos, SEEK_SET);
        fgets(line, 256, fp);
        fputs(line, stdout);
    }
    return 0;
}
