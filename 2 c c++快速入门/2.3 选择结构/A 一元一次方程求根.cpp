#include<stdio.h>
#include<math.h>

int main(){
double a,b,c;
scanf("%lf %lf %lf",&a,&b,&c);
double delta;
delta=b*b-4*a*c;
if(delta>=0){
    delta=sqrt(delta);
double r1,r2;
r1=(-b+delta)/(2*a);
r2=(-b-delta)/(2*a);
printf("r1=%7.2lf\n",r1);
printf("r2=%7.2lf\n",r2);
}else{
printf("No real roots!\n");
}
    return 0;
}