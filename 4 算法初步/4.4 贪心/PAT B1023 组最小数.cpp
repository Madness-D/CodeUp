#include<iostream>
using namespace std;
int main(){
    int aa[10]={0};
    for(int i=0;i<10;i++)
        cin>>aa[i];
    for(int i=1;i<10;i++){// 输出第一个不为0
        if(aa[i]>0){
            cout<<i;
            aa[i]--;
            break;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;i<aa[i];j++){
            cout<<i;
        }
    }
    return 0;
}