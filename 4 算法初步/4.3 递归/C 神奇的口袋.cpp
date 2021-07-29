//输入：n(1<=n<=20);n个物品体积
//输出：组合为40的方式
//一个物品只能使用1次

#include<iostream>
using namespace std;

int vol[22];

int res(int a,int b){//从a个物品中选出体积总和为b的物品
    if(b==0) return 1;//递归边界，刚好填满
    if(a<=0) return 0;//递归边界，遍历完物品
    return res(a-1,b)+res(a-1,b-vol[a]);//前者，不选第a个物品；后者，选第a个物品
}



int main(){
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++)
            cin>>vol[i];
    cout<<res(n,40)<<endl;
    }
    return 0;
}