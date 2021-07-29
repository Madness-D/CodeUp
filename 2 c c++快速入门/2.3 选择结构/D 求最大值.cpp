#include<stdio.h>

int main(){
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    int max=a[0];
    for(int i=1;i<2;i++){
        if(max<=a[i])
        max=a[i];
    }

    printf("%d\n",max);
 
    
}