/*
按字典序输出组合情况
*/

#include <bits/stdc++.h>
using namespace std;
int n,m,p[110];
void dfs(int x)
{
    if (p[0]==m)
    {
        for (int j=1;j<=p[0];j++)
            printf("%d ",p[j]);
            //cout<<p[j]<<" ";
        //cout<<endl;
        printf("\n");
        return ;
    }
    for (int i=x;i<=n;i++)
    {
        p[++p[0]]=i;
        dfs(i+1);
        p[p[0]--]=0;
    }
}
int main()
{
    cin>>n>>m;
    dfs(1);
    return 0;
}
