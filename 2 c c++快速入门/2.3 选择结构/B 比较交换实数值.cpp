#include<stdio.h>

int main(){
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(a>b)
        printf("%.2lf %.2lf\n",b,a);
    else
        printf("%.2lf %.2lf\n",a,b);
    
}