//请输入高度h，输入一个高为h，上底边长为h 的等腰梯形（例如h=4，图形如下）。
//底边：3h-2
//第i行：h-i，h+2i-2，h-i
#include<iostream>
using namespace std;
int main(){
    int m;
    while(cin>>m){
        for(int count=0;count<m;count++){
            int h;
            cin>>h;
            for(int i=1;i<=h;i++){
                for(int j=0;j<h-i;j++){cout<<" ";}
                for(int j=0;j<h+2*i-2;j++){cout<<"*";}
                for(int j=0;j<h-i;j++){cout<<" ";}
                cout<<"\n";
            }

        }
    }
    return 0;
}
