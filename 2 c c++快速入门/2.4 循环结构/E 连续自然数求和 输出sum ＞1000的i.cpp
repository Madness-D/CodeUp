#include<stdio.h>
#define MAXN 10000

int main(){
    int n;
    int sum=0;
    scanf("%d\n",&n);
    int i;
for(i=1;i<=MAXN;i++){
sum+=i;
if(sum>1000)
break;
}
printf("%d\n",i);
}