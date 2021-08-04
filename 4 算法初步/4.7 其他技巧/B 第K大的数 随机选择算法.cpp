/*
随机选择算法，基于上一节的随机快排
主元确定位置后，就知道主元是第几大的元素，再在左区间或者右区间，重复运行
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int Maxn = 1000010;

int partition(int data[], int l, int r) {
    // 初始化种子
    srand((unsigned)time(nullptr));
    // 随机选取枢轴元素
    swap(data[l], data[rand() % (r - l + 1) + l]);
    int v = data[l];
    // [l+1, i] <= v, [j, r) >= v
    int i = l + 1, j = r;
    while (true) {
        // 依次找到两边不满足的元素，交换
        while (i <= r && data[i] < v) i++;
        while (j >= l + 1 && data[j] > v) j--;
        if (i > j) break;
        swap(data[i], data[j]);
        i++;
        j--;
    }
    swap(data[l], data[j]);
    return j;
}
int fastSearchKNum(int data[], int l, int r, int k) {
    int p = partition(data, l, r);
    // 包含枢轴点的左部长度
    int L = p - l + 1;
    if (L == k) { // 情况1 枢轴元素即为第k大元素
        return data[p];
    }
    else if (k < L) { // 情况2 第k大元素在左部
        return fastSearchKNum(data, l, p - 1, k);
    }
    else { // 情况3 第k大元素在右部
        return fastSearchKNum(data, p + 1, r, k - L);
    }
}


int main() {
    int m, n;
    int a[Maxn];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ob = fastSearchKNum(a, 0, n - 1, n  - m);
    cout << a[ob] << endl;
    return 0;
}