//暴力法，全排列后检查是否符合
#include <iostream>
#include <cstdio>
using namespace std;

int n;
int P[100];
bool hashTable[100] = { false };
int countt = 0;//count是std里已经规定的
void generateP(int index) {
    if (index == n + 1) {//递归边界
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (abs(i - j) == abs(P[i] - P[j])) {//在一条对角线上
                    flag = false;
                }
            }
        }
        if (flag) countt++;
        return;
    }
    for (int x = 1; x <= n; x++) {
        if (hashTable[x] == false) {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}

int main() {
    n = 8;//棋盘数
    generateP(1);
    cout << countt << endl;
    return 0;
}