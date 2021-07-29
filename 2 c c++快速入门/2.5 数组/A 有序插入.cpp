#include<stdio.h>

int main() {
    int a[10];
    for (int i = 0; i < 9; i++) {
        scanf("%d ", &a[i]);
    }
    int b;
    scanf("%d", &b);
    int flag;
    for (int i = 0; i < 9; i++) {
        if (a[i] >= b) {
            flag = i; break;
        }
    }
    for (int i = 9; i > flag; i--) {
        a[i] = a[i - 1];
    }
    a[flag] = b;

    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}