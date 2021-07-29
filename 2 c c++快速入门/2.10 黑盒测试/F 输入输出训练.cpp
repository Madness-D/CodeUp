#include<stdio.h>

int main(){
    int T;
    int sum,n;
    while(scanf("%d",&T)!=EOF){     //!=EOF   
        for(int i=0;i<T;i++){
            scanf("%d",&n);
            sum+=n;
        }
        printf("%d\n",sum);
        sum=0;
    }
    return 0;
}