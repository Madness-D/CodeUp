#include<stdio.h>

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){//EOF,End Of File
        printf("%d\n\n",a+b);
    }
    return 0;
}