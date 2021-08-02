/*
归并排序
        两两分一组，排序，合并，然后再排序，合并……
        合并的方法：见序列合并，双指针
非递归实现：每次分组的组内元素个数为2的幂，令step=2，然后每个step内排序、合并(前step/2的元素和后step/2的元素通过merge函数合并)；然后step*2
 */

#include<iostream>
#include<algorithm>
using namespace std;

const int Maxn = 100010;

//将数组A的两个区间合并
void merge(int a[], int L1, int R1, int L2, int R2) {
    int i = L1, j = L2;
    int temp[Maxn], index = 0;//临时存放合并后的数组
    while (i <= R1 && j <= R2) {//合并
        if (a[i] <= a[j]) {
            temp[index++] = a[i++];
        }
        else {
            temp[index++] = a[j++];
        }
    }
    while (i <= R1) temp[index++] = a[i++];
    while (j <= R2) temp[index++] = a[j++];
    for (int k = 0; k < index; k++) {//temp赋值给a的[L1,R2]区间
        a[L1 + k] = temp[k];
    }
}

//归并排序，非递归实现
void mergeSort(int a[], int n) {
    //step为每次分组内的元素个数
    for (int step = 2; step / 2 <= n; step *= 2) {
        //step的 前半部分和后半部分的元素合并
        for (int i = 0; i <= n; i += step) {
            int mid = i + step / 2 - 1;
            if (mid + 1 <= n) {//如果右子区间存在元素则合并
                merge(a, i, mid, mid + 1, min(i + step - 1, n));
            }
        }
    }
}

int main() {
    int a[Maxn];
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        mergeSort(a, n-1);
        for (int i = 0; i < n; i++)
            cout << a[i] << "\n";

    }
    return 0;
}