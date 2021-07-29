#include<stdio.h>
int main() {
    char  a[100];
    char b[100];
    gets(a);//获取字符
    gets(b);
    int c = 0;
    for (int i = 0; i < 100; i++) {
        if (a[i] == b[i]) {
            continue;
        }
        else {
            c = a[i]-b[i];
            break;
        }

    }
    printf("%d\n", c);
    return 0;
}