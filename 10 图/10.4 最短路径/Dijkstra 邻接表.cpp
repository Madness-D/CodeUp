#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXV=1000;//最大顶点数
const int INF=1000000000;//很大的数，作为距离的初始值

struct Node{
    int v,dis;//v为边的目标顶点,dis为边权
};

vector<Node> Adj[MAXV];//邻接表
int n;//顶点数
int d[MAXV];//从起点到各点的最短路径长度
bool vis[MAXV]={false};//标记数组

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

        //只有下面的for循环和邻接矩阵不一样
        for(int j=0;j<Adj[u].size();j++){
            int v=Adj[u][j].v;//直接获得u可达顶点v
            if(vis[v]==false && d[u]+Adj[u][j].dis<d[v]){
                //如果v未被访问且以u为中介点可以使d[v]更优,则优化d[v]
                d[v]=d[u]+Adj[u][j].dis;
            }
        }
    }
}