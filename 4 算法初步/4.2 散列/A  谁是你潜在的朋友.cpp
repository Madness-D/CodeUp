#include<iostream>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m  && n) {
        int Book[205] = { 0 };
        int people[205];
        for (int i = 0; i < n; i++) {
            cin >> people[i];
            Book[people[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (Book[people[i]] > 1)
                cout << Book[people[i]] - 1 << endl;
            else
                cout << "BeiJu" << endl;
        }
    }

    return 0;
}