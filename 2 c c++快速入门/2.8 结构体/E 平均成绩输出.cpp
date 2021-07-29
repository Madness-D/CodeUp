#include<stdio.h>
#include<string.h>

struct student{
    int num;
    char name[20];
    int gr1;
    int gr2;
    int gr3;
}stu[10];

void input(struct student stu[]){
    for(int i=0;i<10;i++){
        scanf("%d %s %d %d %d",&stu[i].num,stu[i].name,&stu[i].gr1,&stu[i].gr2,&stu[i].gr3);
    }
}

void aver(struct student stu[]){
    double sum1=0.0,sum2=0.0,sum3=0.0;
    for(int i=0;i<10;i++){
        sum1+=stu[i].gr1;
        sum2+=stu[i].gr2;
        sum3+=stu[i].gr3;
    }
    printf("%.2f %.2f %.2f\n",sum1/10.0,sum2/10.0,sum3/10.0);
}

void fun1(struct student stu[]){
    int sum[10];
    for(int i=0;i<10;i++){
        sum[i]=stu[i].gr1+stu[i].gr2+stu[i].gr3;
}
    int flag=0,maxsum=sum[0];
    for(int i=0;i<10;i++){
        if(maxsum<sum[i]){
            flag=i;
         maxsum = sum[i];
        }
}
    printf("%d %s %d %d %d\n",stu[flag].num,stu[flag].name,stu[flag].gr1,stu[flag].gr2,stu[flag].gr3);

}

int main(){
    input(stu);//输入的参数，不是stu[]或stu[5]
    aver(stu);
    fun1(stu);
    return 0;
}