//判断通信系统是否符号要求
//判断是不是只有一个集合
//并且没有环？
#include<vector>
#include<iostream>
using namespace std;

vector<int> father;

void init(int N) {
    for (int i = 1; i <= N; i++) {
        father[i] = i;//或者=-1
    }
}
int findFather(int x) {
    if (x == father[x]) return x;
    else {
        int F = findFather(father[x]);//递归找根节点F
        father[x] = F;
        return F;
    }
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faB] = faA;
    }
}

int main() {
    int N, M;
    while (cin >> N >> M && N && M) {//test

        father.resize(N + 1);
        init(N);
        int a, b;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            Union(a, b);
        }
        if (M < N - 1) {
            cout << "No\n";
            continue;

        }
        int flag;
        for (flag = 1; flag < N; flag++) {
            if (father[flag] != father[flag + 1])
                break;
        }

        if (flag == N) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }

    }
    return 0;
}