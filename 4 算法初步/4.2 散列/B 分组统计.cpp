#include<iostream>
#include<cstring>
using namespace std;

int hashTable[1005][1005];

int main(){
    int m,n,a[110],t;
    cin>>m;
    while(m--){
        cin>>n;//n个数
        //输入
        for(int i=0;i<n;i++){
            cin>>a[i];
            hashTable[0][a[i]]=1;
        }
        //输入分组情况
        for(int i=0;i<n;i++){
            cin>>t;//t为分组
            hashTable[t][a[i]]++;
            if(hashTable[t][0]==0)
                hashTable[t][0]=1;//置1表示需要输出
        }
        // 输出
        for(int i=1;i<1005;i++){
            if(hashTable[i][0]==1){
                cout<<i<<"={";
                bool flag=false;//控制逗号
                for(int j=1;j<1005;j++){
                    if(hashTable[0][j]==1){
                        if(flag)cout<<",";
                        else flag=true;
                        cout<<j<<"="<<hashTable[i][j];
                    }
                }
                cout<<"}\n";
            }

        }
        memset(hashTable,0,sizeof(hashTable));
    }
return 0;
}