#include<stdio.h>

int main(){
    int N,M;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
    scanf("%d",&M);
        int sum=0,n;
        while(M--){
            scanf("%d",&n);
            sum+=n;
        }
        printf("%d\n",sum);
    
    }

    return 0;
}