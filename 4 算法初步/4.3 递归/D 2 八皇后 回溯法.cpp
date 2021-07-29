//
#include <iostream>
#include <algorithm>
#include<math.h>

using namespace std;

int n=8;//棋盘行/列数
int P[10];
bool hashTable[100] = { false };
int countt = 0;//count是std里已经规定的
int res[100];// 存储串

void generateP(int index) {

    if (index == n + 1) {//递归边界
        int temp=0;
        for(int i=0;i<8;i++){
            temp+=P[i]*(pow(10,7-i));
        }
        countt++;//能够到达边界的一定是合法的
        res[countt]=temp;
        return;
    }

    for (int x = 1; x <= n; x++) {
        if (hashTable[x] == false) {
            bool flag = true;//表示未冲突
            for(int pre=1;pre<index;pre++){//遍历之前的皇后，检查是否冲突
                if (abs(index-pre) == abs(x-P[pre])) {//在一条对角线上
                    flag = false;
                    break;
                }
            }
            if(flag){
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
            }
            
        }
    }
}

int main() {
    generateP(1);
    sort(res,res+92);
    int mm;
    while(cin>>mm){
        cout<<res[mm]<<endl;
    }
    return 0;
}