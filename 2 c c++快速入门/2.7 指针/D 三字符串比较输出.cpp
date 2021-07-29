//输入3个字符串，按从小到大的顺序输出。要求使用指针的方法进行处理。

#include<stdio.h>
#include<string.h>
int main(){
    char str[3][20];
    char *p[3],*t;
    for(int i=0;i<3;i++){
    scanf("%s",str[i]);
    p[i]=str[i];
    }
    if(strcmp(p[0],p[1])>0) 
        t=p[0],p[0]=p[1],p[1]=t; 
    if(strcmp(p[0],p[2])>0) 
        t=p[0],p[0]=p[2],p[2]=t; 
    if(strcmp(p[1],p[2])>0) 
        t=p[1],p[1]=p[2],p[2]=t; 
    printf("%s\n%s\n%s\n",p[0],p[1],p[2]); 
}