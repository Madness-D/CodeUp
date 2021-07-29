// 输入：N+N个数，输出：第一个独一无二的数；或者“None”
//7 5 31 5 88 67 88 17, 输出31
#include<iostream>
#include<cstring>
using namespace std;
int hashTable[10010];
int a[100010];
int main(){
    int N;
    while(cin>>N){
        for(int i=0;i<N;i++){
            cin>>a[i];
            hashTable[a[i]]++;
        }
        int flag=0;
        for(int i=0;i<N;i++){
            if(hashTable[a[i]]==1){
                cout<<a[i]<<endl;
                flag=1;
                break;
            }
        }
        if(!flag){
            cout<<"None"<<endl;
        }
    memset(hashTable,0,sizeof(hashTable));
    }
    return 0;
}