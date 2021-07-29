#include<stdio.h>
#define MAXN 10000

int main(){
    int n;
    int sum=0;
    scanf("%d\n",&n);
for(int i=1;i<=MAXN;i++){
sum+=i;
if(i==n)
break;
}
printf("%d\n",sum);
}