#include<stdio.h>

int main(){
    double a[3];
    scanf("%lf %lf %lf",&a[0],&a[1],&a[2]);
    int i,j ,temp;
 for(i=0;i<2;i++){
     for(j=0;j<2-i;j++){
         if(a[j]>a[j+1]){
            temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
         }
     }
 }
    printf("%.2lf %.2lf %.2lf\n",a[0],a[1],a[2]);
 
    
}