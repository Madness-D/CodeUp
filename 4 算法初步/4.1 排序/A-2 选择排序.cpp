//选择排序
//在未排序序列中找到最小元素，存放到已排序序列的末尾
//不稳定排序
#include<iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n;
    while(cin>>n){
        int a[100];
        for(int i=0;i<n;i++)
            cin>>a[i];
    //找出最小值，移到未排序部分的最左侧
    for (int i = 0; i < n; i++)
    {   int minIndex=i;// 从未排序的第一个开始遍历
        for(int j=i;j<n;j++){
            if(a[j]<a[minIndex]){
                minIndex=j;//最小值下标
            }
        }

       swap(a[i],a[minIndex]); //交换，导致不稳定
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
        }
        cout << endl;
    
    }
    return 0;
}