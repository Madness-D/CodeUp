//bubble sort
//比较相邻的两个元素，逆序则交换
//第一次遍历后，最大元素排到队尾
//第二次遍历，不包含最后一个，遍历后最大两个元素排在队尾
//*** 第i次循环，仅遍历前n-1-i个元素
//循环至全部有序
//属于稳定排序

#include<iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int n;
    while (cin >> n) {
        int a[100];
        for (int i = 0; i < n; i++) { cin >> a[i]; }
        for(int i=0;i<n-1;i++){
            for (int j = 0; j < n-1-i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}