#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    cin>>a;
    int len=a.length();
    int flag=1;
    for(int i=0;i<len/2;i++){
        if(a[i]!=a[len-1-i]){
            flag=0;break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}