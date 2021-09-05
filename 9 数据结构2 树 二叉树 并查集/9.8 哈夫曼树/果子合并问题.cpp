#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

//指定底层使用long long，使用vector，排序方式：从小到大，即小顶堆
priority_queue<long long,vector<long long>,greater<long long>> q;

int main(){
    int n;
    long long temp,x,y,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        q.push(temp);
    }
    while(q.size()>1){
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        q.push(x+y);
        ans+=x+y;
    }
    cout<<ans<<'\n';
    return 0;

}
