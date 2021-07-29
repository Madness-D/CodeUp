#include<iostream>
using namespace std;

int fab(int a) {
    if (a == 1)
        return 0;
    if (a == 2)
        return 1;
    else
        return fab(a - 1) + fab(a - 2);
}
int main() {
    int m;
    while (cin >> m) {
        while (m--) {
            int n;
            cin >> n;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= 2*(n - i); j++)
                    cout << " ";
                for (int j = 1; j <= 2 * i - 1; j++)
                    cout << fab(j)<<" ";
                cout << endl;
            }
        }
    }
    return 0;
}