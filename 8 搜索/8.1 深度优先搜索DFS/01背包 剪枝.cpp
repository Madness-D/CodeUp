/*
岔道口：对于每件物品，选择放入背包还是不选
死胡同：选择的物品重量总和超过背包容量V，返回最近的岔道口
*/

#include<cstdio>

const int maxn=30;
int n,v,maxValue=0;//物品件数n，背包容量v，最大价值maxValue
int w[maxn],c[maxn];//重量 体积
//DFS函数，index为当前处理的物品编号
//sumW和sumC为当前的总重量和总价值
void DFS(int index,int  sumW,int sumC){
    if(index==n){
        return ;
    }
    //岔道口，两种选择, 但是剪枝
    DFS(index+1,sumW,sumC);
    if(sumW+w[index]<=v){//满足可选条件
        if(sumC+c[index]>maxValue){
            maxValue=sumC+c[index];
        }
    DFS(index+1,sumW+w[index],sumC+c[index]);}
}

int main(){
    scanf("%d %d",&n,&v);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    DFS(0,0,0);
    printf("%d\n",maxValue);
    return 0;
}