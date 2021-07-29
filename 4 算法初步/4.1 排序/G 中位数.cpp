#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    int a[10000];
    while(cin>>N && N){
        for(int i=0;i<N;i++)
            cin>>a[i];
        sort(a,a+N);
        if(N%2==0){
            cout<<(a[N/2]+a[N/2-1])/2<<endl;
        }else{
            cout<<a[N/2]<<endl;
        }
    }
    return 0;
}