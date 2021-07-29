#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct student{
    char ID[10];
    char name[10];
    int grade;
}stu[100010];

bool cmp1(student stu1,student stu2){//学号排序
    return strcmp(stu1.ID,stu2.ID)<0;
}
bool cmp2(student stu1,student stu2){//姓名非递减字典序，相同则学号递增
    if(stu1.name!=stu2.name)    return strcmp(stu1.name,stu2.name)<0;
    else return  strcmp(stu1.ID,stu2.ID)<0;   
}
bool cmp3(student stu1,student stu2){//成绩非递减字典序，相同则学号递增
        if(stu1.grade!=stu2.grade)    return stu1.grade<stu2.grade;
    else return  strcmp(stu1.ID,stu2.ID)<0; 
    
}
int main (){
    int N,C;//N为输入样本数，C不一样，排序关键字不一样
    int mm=0;
    while((cin>>N>>C)&& N ){
        mm++;
    for(int i=0;i<N;i++){
            cin>>stu[i].ID>>stu[i].name>>stu[i].grade;
        }
    if(C==1){//按学号递增
            sort(stu,stu+N,cmp1);
    }
    if(C==2){//姓名非递减字典序，相同则学号递增
            sort(stu,stu+N,cmp2);
    }
    if(C==3){//成绩非递减序，相同则学号递增
            sort(stu,stu+N,cmp3);
    }
    cout<<"Case "<<mm<<":"<<endl;
    for(int i=0;i<N;i++){
        printf("%s %s %d\n",stu[i].ID,stu[i].name,stu[i].grade);
    }
    }
return 0;
}