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
#include<algorithm>
using namespace std;

const int MAXV=510;
const int INF=1000000000;

//
//
//
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
    for(int i=0;i<n;i++){
        int u=-1;MIN=INF;
    }

}