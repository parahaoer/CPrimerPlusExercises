#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char fileName[255];
    char targetStr[255];
    char buf[256];
    char *line;
    int targetStrCount = 0;
    scanf("%s %s", fileName, targetStr);
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("open %s failed", argv[1]);
        exit(EXIT_FAILURE);
    }

    int targetStrLen = 0;
    for (int i = 0; i < sizeof(targetStr); i++) {
        if (targetStr[i] != '\0') {
            targetStrLen++;
        } else {
            break;
        }
    }

    while (fgets(buf, 256, fp) != NULL) {
        
        line = buf;
        while ((line = strstr(line, targetStr) + targetStrLen) != NULL)
            targetStrCount++;    
    }
    printf("文件%s中目标字符%s的数量为%d", argv[1], argv[2], targetStrCount);
    fclose(fp);
    return 0;
}
