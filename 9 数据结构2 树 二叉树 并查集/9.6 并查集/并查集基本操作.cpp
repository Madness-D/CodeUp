#include<vector>
#include<iostream>
using namespace std;

vector<int> father;

void init(vector<int> &father,int N){ 
    for(int i=1;i<=N;i++){
        father[i]=i;//或者=-1
    }
}
//返回x所在集合的根节点
int findFather(int x){
    while(x!=father[x]){
        x=father[x];
    }
    return x;
}
int findFatherRecursion(int x){
    if(x==father[x]) return x;
    else return findFatherRecursion(father[x]);
}

void Union(int a,int b){
    int faA=findFather(a);
    int faB=findFather(b);
    if(faA!=faB){
        father[faA]=faB;
    }
}

int findFatherZip(int x){
    int a=x;//暂存x，下面的循环会导致x变成根节点
    while(x!=father[x]){
        x=father[x];
    }
    //这里，x为根节点，下面需要将路径（原来的x，现在的a，到根节点，现在的x）上所有的结点的father改为根节点
    while(a!=father[a]){
        int z=a;//回溯，因此a会指向a的父亲节点，需要将a存在z里
        a=father[a];
        father[z]=x;
    }
    return x;
}

int findFatherZipRecursion(int x){
    if(x==father[x]) return x;
    else{
        int F=findFatherZipRecursion(father[x]);//递归找根节点F
        father[x]=F;
        return F;
    }
}