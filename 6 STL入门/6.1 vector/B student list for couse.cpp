/*
输入
        int n，<=40000 学生数       int k <=2500 课程数
        N行： 学生name， c <=20 学生选课数 c个整数：所选课程
输出
        课程代码 整数course， 选课人数 整数m
        m行：选课学生姓名,按字母序排列
思路：

*/
#pragma warning(disable:4996)；
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int K = 2510;

vector<string> res[K];

bool cmp(string s1, string s2) {
    return s1 < s2;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        string nam;
        nam.resize(5);
        int num;//学生选课数目
        scanf("%s %d", &nam[0], &num);
        int cour;
        while (num--) {
            scanf("%d", &cour);
            res[cour].push_back(nam);
        }
    }

    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, res[i].size());
        sort(res[i].begin(), res[i].begin()+res[i].size(), cmp);
        for (int j = 0; j < res[i].size(); j++) {
            //c_str() 是string的函数，将string转化为char数组
            printf("%s\n", res[i][j].c_str());
            //cout << res[i][j] << endl;
        }
    }
    return 0;

}