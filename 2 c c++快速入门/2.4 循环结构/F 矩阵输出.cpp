#include<stdio.h>

int main(){
    for(int i=1;i<5;i++){
        for(int j=1;j <6;j++){
            printf("%3d",i*j);
        }
        printf("\n");
    }
    return 0;
}