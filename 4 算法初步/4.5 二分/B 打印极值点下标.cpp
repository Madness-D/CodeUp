#include<iostream>
using namespace std;

int a[85];

int main(){
    int num;
    while(cin>>num){
        int n;
        while(num--){
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            if(a[0]!=a[1])//考虑前两个相等的情况
                cout<<0<<" ";
            for(int i=1;i<n-1;i++){
                if(((a[i]>a[i-1])&&(a[i]>a[i+1]))||((a[i]<a[i-1])&&(a[i]<a[i+1])))
                    cout<<i<<" ";
            }
            if(a[n-1]!=a[n-2])//考虑后两个相等的情况
                cout<<n-1<<endl;
        }

    }
    return 0;
}