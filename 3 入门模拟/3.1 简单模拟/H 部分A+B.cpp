#include<cstdio>

int fun(int A,int DA){
    int PA=0;
    while(A){
        if(A%10==DA){
            PA=PA*10+DA;
        }
        A/=10;
    }
    return PA;
}

int main(){
    int A,DA,B,DB;
    while(scanf("%d %d %d %d",&A,&DA,&B,&DB)!=EOF){
        printf("%d\n",fun(A,DA)+fun(B,DB));
    }
    return 0;
}