#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){cout<<" ";}
            for(int j=0;j<n-i+1;j++){cout<<"* ";}
            cout<<"\n";
        }
        for(int i=n+1;i<2*n;i++){
            for(int j=0;j<2*n-1-i;j++){cout<<" ";}
            for(int j=0;j<i+1-n;j++){cout<<"* ";}
            cout<<"\n";
        }
    }

    return 0;
}