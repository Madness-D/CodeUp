#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;



int main(){
    int n;
    while(cin>>n  && n){
    priority_queue<int,vector<int>,greater<int>> q;
    int temp,x,y,ans=0;
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
    }
    return 0;

}
