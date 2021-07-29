//输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。要求用3个函数实现，分别为输入10个数、进行处理、输出10个数。要求使用指针的方法进行处理
//找到最大、最小值分别交换至制定位置

#include<stdio.h>

int a[10];

void input(int* p){
    for(;p<a+10;p++){
        scanf("%d ",p);
    }
}

void output(int* q) {
	for(; q < a+10; q++) {
		printf("%d ", *q);
	}
}

void func(int* k){
    int max=*k,min=*k;
    for(;k<a+10;k++){
        if(*k>max)
            max=*k;
        if(*k<min)
            min=*k;
    }
    for(k=a;k<a+10;k++){
        if(*k==max){
            int t=*k;
            *k=a[9];
            a[9]=t;
        }
         if(*k==min){
            int t=*k;
            *k=a[0];
            *a=t;//*a是整数，a是指针
        }
    }
 
}

int main(){
    input(a);
    func(a);
    output(a);
    return 0;
}