#include<stdio.h>
//错误原因：值传递与引用传递
void swap(int a,int b){
    int t=a;
    a=b;
    b=t;
}

int main() {
    int a[10];
    for (int i = 0; i <10; i++) {
        scanf("%d ", &a[i]);
    }
    for(int i=0;i<5;i++){
        swap(&a[i],&a[10-i-1]);
    }
    for(int i=0;i<10;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}