
#include<stdio.h>
#include<string.h>

int main() {

    struct person {
        char name[20];
        int count;
    }leader[3] = { "Li", 0, "Zhang", 0, "Fun", 0 };

    int n;
    scanf("%d", &n);
    for (int i = 0; i <=n; i++) { //为什么是<=?
        char na[20];
        gets(na);
        if (strcmp(na,leader[0].name)==0)
            (leader[0].count)++;
        if (strcmp(na, leader[1].name) == 0)
            leader[1].count++;
        if (strcmp(na, leader[2].name) == 0)
            leader[2].count++;
    }

    for (int i = 0; i < 3; i++) {
        printf("%s:%d\n",leader[i].name, leader[i].count);
    }
    return 0;


}