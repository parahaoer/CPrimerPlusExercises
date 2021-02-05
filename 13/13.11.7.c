#include<stdio.h>

char *mystrncpy(char *srcStr, char *dstStr, int n) {

    int i = 0;
    for (; srcStr[i] != '\0' && i < n; i++) {
        dstStr[i] = srcStr[i];
    }
    dstStr[i] = '\0';
    
    return dstStr;
}

int main(int argc, char const *argv[])
{
    char srcStr[256];
    char dstStr[256];
    char buf[256];
    int n = 0;
    // fgets()函数按行读取标准输入到buf数组中
    while (fgets(buf, 256, stdin) != NULL) {
        //sscanf()函数从数组buf中读取字符并按照指定的格式对其转换，函数返回被转换的输入值的个数。
        if (sscanf(buf, "%s %d", srcStr, &n) != 2) {
            fprintf(stderr, "Bad input skipped: %s", buf);
            continue;
        }
        printf("%s\n", mystrncpy(srcStr, dstStr, n));
    }
    return 0;
}
