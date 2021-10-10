/*
题意：给出N个城市，M条无向边，每个城市中有一定数目的救援小组
给出起点和重点，求起点到终点的最短路径条数以及最短路径上的救援小组数目之和
如果有多条最短路径，输出救援小组数目之和最大的

输入：
    顶点数N，边数M，起点C1，终点C2
    N个整数：各点点权 
    M行： 边起点 边终点 边权

输出：一行，最短路径的条数，可能的最大的点权之和
*/
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXV=510;//最大顶点数
const int INF=1000000000;//无穷大

//n为顶点数，m为边数，st和ed为起点和终点
//G为邻接矩阵，weight为点权
//d[]记录最短距离,w[]记录最大点权之和，num[]记录最短路径条数
int n, m,st,ed,G[MAXV][MAXV],weight[MAXV];
int d[MAXV],w[MAXV],num[MAXV];
bool vis[MAXV]={false};

void Dijkstra(int s){
    //memeset更快
    fill(d,d+MAXV,INF);
    memset(num,0,sizeof(num));
    fill(w,w+MAXV,0);
    d[s]=0;
    w[s]=weight[s];
    num[s]=1;
    for(int i=0;i<n;i++){//循环n次
        int u=-1,MIN=INF;//u使d[u]最小,MIN存放该最小的d[u]
        for(int j=0;j<n;j++){//找到未访问的顶点中d[]最小的,赋值给u和MIN
            if(vis[j]==false && d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        //找不到小于INF的d[u],说明剩下的点和起点不连通
        if(u==-1) return;
        vis[u]=true;//标记为已访问
        for(int v=0;v<n;v++){
            //如果v未访问 && u能到达v && 以u为中介点可以令d[v]更优
            if((!vis[v]) && G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){//以u为中介点可以令d[v]更优
                d[v]=d[u]+G[u][v];//更新最短路径
                w[v]=w[u]+weight[v];//更新点权和
                num[v]=num[u];
                }else if(d[u]+G[u][v]==d[v]){//路径长度相同
                    if(w[u]+weight[v]>w[v]){//如果点权和更大,则更新点权和
                        w[v]=w[u]+weight[v];
                    }
                    num[v]+=num[u];//更新最短路径条数
                }
            }
        }
    }
}

int main(){
    cin>>n>>m>>st>>ed;
    for(int i=0;i<n;i++){
        cin>>weight[i];//读入点权
    }
    int  u,v;
    fill(G[0],G[0]+MAXV*MAXV,INF);//初始化图G
    for(int i=0;i<m;i++){
        cin>>u>>v;
        cin>>G[u][v];
        G[v][u]=G[u][v];//单边
    }
    Dijkstra(st);
    cout<<num[ed]<<" "<<w[ed]<<endl;
    return 0;
}