#include<stdio.h>

void storageChar(char *a, int n) {
    
    // 读取输入n后面的一个空格来跳过它
    char ch = getchar();
    int i = 0;
    for (; i < n && (ch = getchar()); i++) {
        a[i] = ch;
    }
    a[i] = '\0';
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    char a[n + 1];
    storageChar(a, n);
    printf("%s", a);
    return 0;
}
