//n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
//side=n1=n3=(N+2)/3
//mid=N-side*2


#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str[90];
    while (cin >> str) {
        int len;
        len = strlen(str);
        int side, mid;
        side = (len + 2) / 3;
        mid = len - 2 * side;
        for (int i = 0; i < side - 1; i++) {
            cout << str[i];
            for (int j = 0; j < mid; j++) {
                cout << " ";
            }
            cout << str[len - 1 - i] << endl;
        }
        for (int i = side - 1; i <= len  - side; i++) {
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}
