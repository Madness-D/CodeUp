/* 
归并排序
        两两分一组，排序，合并，然后再排序，合并……
        合并的方法：见序列合并，双指针
递归实现：反复讲区间分成两半
 */

#include<iostream>
using namespace std;

const int Maxn=100010;

//将数组A的两个区间合并
void merge(int a[],int L1,int R1,int L2,int R2){
    int i=L1,j=L2;
    int temp[Maxn],index;//临时存放合并后的数组
    while(i<=R1 && j<=R2){//合并
        if(a[i]<=a[j]){
            temp[index++]=a[i++];
        }else{
            temp[index++]=a[j++];
        }
    } 
    while(i<=R1) temp[index++]=a[i++];
    while(j<=R2) temp[index++]=a[j++];          
    for(int k=0;k<index;k++){//temp赋值给a的[L1,R2]区间
        a[L1+k]=temp[k];
    }
}

//归并排序
void mergeSort(int a[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,mid+1,right);
    }
}

int main(){
    int a[Maxn];
    int m;
    cin>>m;
    while(m--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        mergeSort(a,0,n-1);
        for(int i=0;i<n;i++)
            cout<<a[i]<<"\n";
    
    }
    return 0;
}