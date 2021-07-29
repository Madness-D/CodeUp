#include<stdio.h>

int main(){
    int F,a,b;
    scanf("%d",&F);
    while(F--){
        scanf("%d %d",&a,&b);
        printf("%d\n",a+b);
    }
    return 0;
}