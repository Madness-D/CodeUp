/*
输入
        整数    L 裂纹长度      N 木块 数
        N个整数 木块的长度
输出
        需要的木块数
        或者impossible
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int MaxN=610;
int a[MaxN];
bool cmp(int a,int b){
    return a>b;
}

int main(){
    int L,N;
    while(cin>>L>>N && L){
        int sum=0;
        int res=0;
        //输入
        for(int i=0;i<N;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum<L)
            cout<<"impossible\n";
        else{
            sort(a,a+N,cmp);//木块从大到小排序
            int j=0;
            while(L>0){
                L-=a[j];
                j++;
                res++;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}