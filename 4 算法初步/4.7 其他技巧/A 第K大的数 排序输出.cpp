#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int m,n;
    int a[1000010];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    cout<<a[m-1]<<endl;
}