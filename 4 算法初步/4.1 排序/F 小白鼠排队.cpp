#include<iostream>
#include<algorithm>
using namespace std;
struct Rat{
    int weight;
    char color[12];
}rat[100];

bool cmp(Rat r1,Rat r2){
    return r1.weight>r2.weight;
}
int main(){
    int N;
    while(cin>>N){
        for(int i=0;i<N;i++){
            cin>>rat[i].weight>>rat[i].color;
        }
        sort(rat,rat+N,cmp);
        for(int i=0;i<N;i++){
            cout<<rat[i].color<<'\n';
        }
        
    }
    return 0;
}