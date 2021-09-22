#include<iostream>
#include<algorithm>
using namespace std;

const int MAXV=1000;//最大顶点数
const int INF=1000000000;//很大的数，作为距离的初始值

int n,G[MAXV][MAXV];//n为顶点数，G为图，邻接矩阵
int d[MAXV];//最短路径
bool vis[MAXV]={false};

void Dijkstra(int s){//参数s为起点
    fill(d,d+MAXV,INF);//将整个d数组赋值为INF，慎用memset
    d[s]=0;//起点s到达自身的距离为0
    for(int i=0;i<n;i++){//第一层循环
        int u=-1,MIN=INF;//u,未访问节点中使d[u]最小的节点 ,MIN用于存放最小的d[u]
        for(int j=0;j<n;j++){//第二层循环,找到u
            if(vis[j]==false && d[j]<MIN){//如果是未访问节点,且d更小,更新u和MIN
                u=j;
                MIN=d[j];
            }
        }
        //没有找到小于INF的d[u],说明剩下的顶点和起点s不连通
        if(u==-1) return;
        //否则,找到了u
        vis[u]=true;//将u标记为已访问
        for(int v=0;v<n;v++){
            //v未被访问,u能到达v,以u为中介点的d[v]更优
            if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
                d[v]=d[u]+G[u][v];//更新d[v]
            }
        }
    }
}