#include<iostream>
using namespace std;

int fun1(int n){
    if(n==1)
        return  1;
    if(n==2)
        return 2;
    else
        return fun1(n-1)+fun1(n-2);
}

int main(){
    int n;
    while(cin>>n && n){
        cout<<fun1(n)<<endl;
    }
    return 0;
}