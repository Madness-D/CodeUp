/*
二分查找
*/

#include<iostream>
using namespace std;

int erfen(int a[],int n,int x){//n为数组长度，x为要查找的元素
    int left=0,right=n-1,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(a[mid]==x) return mid;
        else if(a[mid]>x){right=mid-1;}
        else{left=mid+1;}
    }
    return -1;
}

int a[210];

int main(){
    int n;
    while(cin>>n && n){
        int tar;
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>tar;
        cout<<erfen(a,n,tar)<<endl;
    }
    return 0;
}
