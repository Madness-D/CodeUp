/*
***********  DFS伪代码
DFS(u){//访问顶点u
    vis[u]=true;//标记u已经被访问
    for(从u出发能到达的所有顶点v)
        if vis[v]==false //如果未访问
            DFS(v);//递归访问v

}

DFSTrave(G){//遍历图G
    for(G的所有顶点u)
        if vis[u]==false
            DFS(u);//调用访问u所在的连通块

}
*/

#include<iostream>
#include<vector>
using namespace std;

//邻接矩阵版,边权为INF表明两点不连通
const int MAXV=1000;//最大顶点数
const int INF=1000000000;

int n,G[MAXV][MAXV];
bool vis[MAXV]={false};

void DFS(int u,int depth){
    vis[u]=true;
    //如果需要对u进行一些操作，在这里进行
    //cout<<u<<endl;
    //下面对从u出发可以到达的分支顶点进行枚举
    for(int v=0;v<n;v++){
        if(vis[v]==false && G[u][v]!=INF){//未被访问且uv连通
        DFS(v,depth+1);
        }
    }
}

void DFSTRave(){
    for(int u=0;u<n;u++){
        if(vis[u]==false){
            DFS(u,1);
        }
    }
}


//邻接表版
vector<vector<int>> Adj(MAXV);

void AdjDFS(int u,int depth){
    vis[u]=true;
    //
    for(int i=0;i<Adj[u].size();i++){
        int v=Adj[u][i];
        if(vis[v]==false){
            AdjDFS(v,depth+1);
        }
    }
}
void AdjDFSTrave(){
    for(int u=0;u<n;u++){
        if(vis[u]==false){
            DFS(u,1);
        }
    }
}
