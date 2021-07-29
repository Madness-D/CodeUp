//写一个函数将一个字符串按反序存放。
//在主函数中输入一个字符串
//通过调用该函数，得到该字符串按反序存放后的字符串，并输出。

#include<stdio.h>
#include<string.h>
    int j=0;//全局变量，主函数也要用
void fun(char a[],char b[]){

int n=strlen(a);
for(int i=0;i<n;i++){
    if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'){
        b[j]=a[i];j++;
    }
}
}

int main(){

    char a[100];
    gets(a);
    char b[100];
    fun(a,b);
    for(int i=0;i<j;i++){
         putchar(b[i]);
    }

}