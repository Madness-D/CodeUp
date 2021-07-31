/*
不能出现对一种药只取它的一部分这样的操作
目标：得到最大体积的当前可用的解药
输入
        整数C 测试数据组数
        第一行：
            正整数n 药水种类
            正整数V 药水体积，都相等
            正整数W 限制条件，配出的药水的浓度不大于W
        第二行
            n个整数，各药水浓度 Pi
输出
        整数Vmax，解药的最大体积
        两位小数 per 解药浓度
        无法配出符合要求的解药 0 0.00
因为体积都相等，因此浓度=∑Pi/mm，mm为选择的种类数
无解的情况：所有药水的浓度都大于W
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int MaxN = 110;
int p[MaxN];

int main() {
    int n, v, w, mm;
    while (cin >> mm) {
        while (mm--) {
            cin >> n >> v >> w;
            for (int i = 0; i < n; i++)
                cin >> p[i];
            sort(p, p + n);
            int num = 0;// 使用的药剂种类数
            int wsum = 0;//浓度和，wsum/num=dense
            double dense = 0;//所配药水浓度，>m则跳出循环

            for (int i = 0; i < n; i++) {
                if ((wsum + p[i]) / (i + 1) <= w) {
                    wsum += p[i];
                    num = i+1;
                }
                else break;
            }
           
            if (wsum == 0)
                cout << "0 0.00" << endl;
            else {
                dense = wsum / num;
                printf("%d %.2f\n", num * v, dense / 100);
            }

        }
    }
    return 0;
}