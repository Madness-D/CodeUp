#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int mart[10][10];
    int m;
    while(cin >> m){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mart[i][j];
        }
    }
    int res[25] = { 0 };//(0，m-1)存行总和；(m,2m-1)存列总和，2m主对角线，2m+1副对角线
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            res[i] += mart[i][j];
            res[m + j] += mart[i][j];
            if (i == j) res[2 * m] += mart[i][j];
            if (j == m - 1 - i) res[2 * m + 1] += mart[i][j];
        }
    }
    sort(res, res + 2 * m + 2, cmp);
    for (int i = 0; i < 2 * m + 2; i++) {
        cout << res[i] << " ";
    }
    }
    return 0;
}