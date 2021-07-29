//每行的第一个数N，表示本行后面有N个数。
//如果N=0时，表示输入结束，且这一行不要计算。
#include<stdio.h>

int main(){
    int T;
    while(scanf("%d",&T),T){
        int sum=0,n;
        while(T--){
            scanf("%d",&n);
            sum+=n;
        }
        printf("%d\n",sum);
    }
    return 0;
}