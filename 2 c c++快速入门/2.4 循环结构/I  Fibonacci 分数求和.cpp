#include<stdio.h>
double Fib(double n){//参数为double，可以输入int
    if(n==1.0||n==2.0)
    return 1.0;
    else
    return Fib(n-1)+Fib(n-2);
}
int main(){
    double frac[20],sum=0.0;
    for(int i=0;i<20;i++){
        frac[i]=Fib(i+3)/Fib(i+2);//数组下标必须为整数
        sum+=frac[i];
    }

    printf("%.6lf",sum);
    return 0;
}