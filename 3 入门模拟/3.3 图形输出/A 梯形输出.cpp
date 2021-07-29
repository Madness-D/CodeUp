#include<iostream>
using namespace std;
//5:5 7 9 11 13(3h-2)
//h+2*i-2个*;
int main(){
    int h;
    while(cin>>h){
        for(int i=1;i<=h;i++){
            for(int j=0;j<(2*h-2*i);j++){
                cout<<" ";
            }
            for(int j=0;j<(h+2*i-2);j++){
                cout<<"*";
            }
            cout<<"\n";
        }
    }
return 0;
}