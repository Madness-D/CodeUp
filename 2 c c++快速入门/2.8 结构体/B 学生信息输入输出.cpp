#include<stdio.h>
#include<string.h>
struct student {
    int num;
    char name[20];
    char sex;
    int age;
};

int main() {
    struct student Stu[20];//C需要struct关键字
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {//
        scanf("%d %s %c %d", &Stu[i].num, Stu[i].name, &Stu[i].sex, &Stu[i].age);
    }
    for (int i = 0; i < n; i++) {//
        printf("%d %s %c %d\n", Stu[i].num, Stu[i].name, Stu[i].sex, Stu[i].age);
    }
    return 0;
}