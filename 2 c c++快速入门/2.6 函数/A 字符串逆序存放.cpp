//写一个函数将一个字符串按反序存放。
//在主函数中输入一个字符串
//通过调用该函数，得到该字符串按反序存放后的字符串，并输出。

#include<stdio.h>
#include<string.h>

void reverse(char a[],int len){
    for(int i=len-1;i>=0;i--){
        putchar(a[i]);
    }
}

int main(){
    int len=0;
    char a[100];
    gets(a);//输入字符串
    len=strlen(a);
    reverse(a,len);
    return 0;
}