//Dijkstra,修改优化d[v]的for循环

//新增边权
for(int v=0;v<n;v++){
    //如果v未被访问 && u能到达v
    if(vis[v]==false&&G[u][v]!=INF){
        if(d[u]+G[u][v]<d[v]){//以u为中介点可以使d[v]更优
            d[v]=d[u]+G[u][v];
            c[v]=c[u]+cost[u][v];
        }else if(d[u]+G[u][v]==d[v]&& c[u]+cost[u][v]<c[v]){
            c[v]=c[u]+cost[u][v];//最短距离相同,则看能否使c[v]更优
        }
    }
}

//新增点权
for(int v=0;v<n;v++){
    //如果v未被访问 && u能到达v
    if(vis[v]==false&&G[u][v]!=INF){
        if(d[u]+G[u][v]<d[v]){//以u为中介点可以使d[v]更优
            d[v]=d[u]+G[u][v];
            w[v]=w[u]+weight[v];
        }else if(d[u]+G[u][v]==d[v]&& w[u]+weight[v]>w[v]){
            w[v]=w[u]+weight[v];//最短距离相同,则看能否使c[v]更优
        }
    }
}

//求最短路径条数
for(int v=0;v<n;v++){
    //如果v未被访问 && u能到达v
    if(vis[v]==false&&G[u][v]!=INF){
        if(d[u]+G[u][v]<d[v]){//以u为中介点可以使d[v]更优
            d[v]=d[u]+G[u][v];
            num[v]=num[u];
        }else if(d[u]+G[u][v]==d[v]){
            num[v]+=num[u];
        }
    }
}