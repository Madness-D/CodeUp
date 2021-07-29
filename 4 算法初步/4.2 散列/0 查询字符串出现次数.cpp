//题目：给出N个字符串，由3个大写字母组成
//给出M个查询字符串，求每个查询字符串在N个字符串中出现的次数

#include<iostream>

const int maxn =100;
char S[maxn][5],temp[5];
int hashTable[26*26*26+10]={0};//3位大写字母，hash表
int haFunc(char S[],int len){
    int id=0;
    for(int i=0;i<len;i++){
        id=id*26+(S[i]-'A');
    }
    return id;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>S[i];
        int id=haFunc(S[i],3);//转换为hash值
        hashTable[id]++;//对应散列表的值++
    }

    for(int i=0;i<m;i++){
        cin>>temp;
        int id=haFunc(temp,3);
        cout<<hashTable[id]<<endl;
    }
    return 0;
}
