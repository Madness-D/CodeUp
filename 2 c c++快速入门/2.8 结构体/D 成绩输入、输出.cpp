#include<stdio.h>
#include<string.h>

struct student{
    int num;
    char name[20];
    int gr1;
    int gr2;
    int gr3;
}stu[5];

void input(struct student stu[]){
    for(int i=0;i<5;i++){
        scanf("%d %s %d %d %d",&stu[i].num,stu[i].name,&stu[i].gr1,&stu[i].gr2,&stu[i].gr3);
    }
}

void prit(struct student stu[]){
    for(int i=0;i<5;i++){
        printf("%d %s %d %d %d\n",stu[i].num,stu[i].name,stu[i].gr1,stu[i].gr2,stu[i].gr3);
    }
}

int main(){
    input(stu);//输入的参数，不是stu[]或stu[5]
    prit(stu);
    return 0;
}