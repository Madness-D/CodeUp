/*
输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。
写三个函数； ①输入10个数；②进行处理；③输出10个数。

似乎没必要使用queue，


需要考虑比较特殊的情况，在交换的过程中，可能存在一个元素发生了两次交换。如果第一个元素是最大的，那么找出一个最小的元素与第一个元素交换后，交换后的这个元素（不是第一个元素）就成为了最大的元素，它需要与最后一个元素交换，因此这个位置的这个元素就要交换两次，先和第一个元素交换，再和最后一个元素交换。如10 ，1，2，3，4，5，6，7，8，9。第一个位置上的元素是最大的，10与1交换后，10再与9交换。如果最后一个元素是最小的，也存在有一个位置上的元素需要交换两次。

*/
#include<iostream>
#include<algorithm>
using namespace std;

int a[10];

void inp( int a[]){
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
}

void func(int a[]){
    int min=a[0],minf=0,max=a[0],maxf=0;
    for(int i=0;i<10;i++){
        if(a[i]>max){
            max=a[i];
            maxf=i;
        }
    }
    swap(a[maxf],a[9]);
        for(int i=0;i<10;i++){

        if(a[i]<min){
            min=a[i];
            minf=i;
        }
    }
    swap(a[minf],a[0]);
}

void outp(int a[]){
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    inp(a);
    func(a);
    outp(a);
    return 0;
}