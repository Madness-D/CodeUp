#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int a[100];
        //输入
        for (int i = 0; i < n; i++) { cin >> a[i]; }
        //排序
        sort(a,a+n);

        //输出
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}