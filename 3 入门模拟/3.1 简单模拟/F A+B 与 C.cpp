#include<cstdio>

int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        long a,b,c;
        scanf("%ld %ld %ld",&a,&b,&c);//a+b可能溢出
        if(a+b>c){
            printf("Case #%d: true\n",i);
        }else{
            printf("Case #%d: false\n",i);
        }
    }

    return 0;
}