#include<stdio.h>

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF,a||b){//EOF,End Of File
        printf("%d\n",a+b);
    }
    return 0;
}