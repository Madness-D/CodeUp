#include<iostream>
using namespace std;

int main(){
    int n,a[100],m,b[100];
    while(cin>>n){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    for(int i=0;i<m;i++){
        int j=0;
        for(;j<n;j++){
            if(b[i]==a[j]){cout<<"YES\n";break;}
            if(j==n-1){cout<<"NO\n";}
        }
    }
    
    }
    return 0;
}