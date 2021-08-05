/*
给出两个集合，计算相似度 
相似度：公共数字/总的不同数字的数目
输入
        正整数N 集合综述
        N行，给出每个集合：元素个数M M个整数
        正整数K
        K行查询，每行：两个set的编号
输出：  一位小数的百分数，如50.0%
思路： 使用N个set来存储
        设计一个函数，参数为两个set，两个整数，sameNum和totalNum，设置为0和一个set的元素数，然后遍历另一个set的元素，在第一个set中出现则sameNum++，否则totalNum++
*/

#include<iostream>
#include<set>
using namespace std;
const int N=52;
set<int> st[N];

void comp(set<int> &s1,set<int> &s2){
    int sameNum=0,totalNum=s2.size();
    for(set<int>::iterator it=s1.begin();it!=s1.end();it++){
        if(s2.find(*it)!=s2.end()) sameNum++;
        else totalNum++;
    }
    printf("%.1f%%\n",sameNum*100.0/totalNum);
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    { int m,x;
    scanf("%d",&m);
    for(int j=0;j<m;j++){
        scanf("%d",&x);
        st[i].insert(x);
    }
    }
    int k;
    scanf("%d",&k);
    int n1,n2;
    while(k--){
        scanf("%d %d",&n1,&n2);
        comp(st[n1],st[n2]);
    }
    return 0;

}