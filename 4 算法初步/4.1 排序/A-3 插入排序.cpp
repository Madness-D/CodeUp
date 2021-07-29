//直接插入排序
//思想：将一个元素插入已有序序列中

#include<iostream>
using namespace std;
/*
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
*/

int main() {
    int n;
    while (cin >> n) {
        int a[100];
        //输入
        for (int i = 0; i < n; i++) { cin >> a[i]; }
        //排序
        for(int i=1;i<n;i++){
            int temp=a[i],j=i;//从j=i向前枚举找到插入位置
            while(j>0 && temp<a[j-1]){//j>1?
            a[j]=a[j-1];
            j--;
            }
            a[j]=temp;
        }

        //输出
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}