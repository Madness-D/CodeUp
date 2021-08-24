//输入，n和m，n是完全二叉树结点数，求m为根节点的子树的结点数
//笨办法：建立二叉树之后遍历
//思考：完全二叉树性质
//dfs，递归遍历 https://blog.csdn.net/weixin_43886377/article/details/104270641
//改进，   https://blog.csdn.net/qq_20679687/article/details/89647642
// 每一层满足题设的结点数量为  最右结点 - 最左结点 +1

#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;

int res;

int dfs(int m, int n) {
    if (2 * m <= n) {
        res++;
        dfs(2 * m, n);
    }
    if (2 * m + 1 <= n) {
        res++;
        dfs(2 * m + 1, n);
    }
    return res;
}

int main() {
    int m, n;
    while (cin >> m >> n && m && n) {
        // res = 1;
        // cout << dfs(m, n) << endl;
         int left, right, cnt=0;
        left = right = m;
        while(left<=n){
            cnt += right - left +1;
            left = left*2;
            right = right*2+1;
            if(right>n) right = n;
        }
        cout<<cnt<<endl;
    }
    return 0;
}