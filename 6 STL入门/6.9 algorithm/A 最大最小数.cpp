#include<iostream>
#include<algorithm>
#include<set>
using namespace std;


int  main(){
    int n,temp;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>temp;
        s.insert(temp);
    }
    set<int>::iterator it=s.end();
    it--;//s.end()指向最后一个元素之后的位置，且不能直接cout中--
    cout<<*it<<" "<<*(s.begin())<<endl;
    return 0;
}