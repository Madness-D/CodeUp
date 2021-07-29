#include<stdio.h>
void swap(int *a,int *b){//参数为指针，引用传递
    int t=*a;
    *a=*b;
    *b=t;
}

int main() {
    int a[10];
    for (int i = 0; i <10; i++) {
        scanf("%d ", &a[i]);
    }
    for(int i=0;i<5;i++){
        swap(a+i,a+(10-i-1));//传递的参数为指针
    }
    for(int i=0;i<10;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}