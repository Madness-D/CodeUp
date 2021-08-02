/*
问题：
        两个递增序列合并成一个递增序列
思路：
        两个指针，分别指向两个序列的首位，比大小决定指针移动方案
        
该文件仅给出了函数实现

*/

#include<iostream>
using namespace std;

int merge(int a[],int b[],int c[],int n,int m){//n:a的元素数，m:b的元素数
    int i=0,j=0,index=0;//index为c的长度，函数返回值
    while(i<n && j<m){
        if(a[i]<=b[j]){
            c[index++]=a[i++];//c[index]=a[i];i++;index++;
        }else{
            c[index++]=b[j++];
        }
    }
    while(i<n) c[index++]=a[i++];
    while(j<m) c[index++]=b[j++];
    return index;
}

