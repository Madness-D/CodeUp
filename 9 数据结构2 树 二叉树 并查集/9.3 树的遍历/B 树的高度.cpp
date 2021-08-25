#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;

int n;
int maxn;

struct node
{
    int data;
    int level;
    vector<int> child;//存子树下标
}Node[1000];

void layer()
{
    queue<int> q;
    q.push(1);
    Node[1].level = 1;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(int i=0; i<(int)Node[top].child.size(); i++)
        {
            int child = Node[top].child[i];
            Node[child].level = Node[top].level+1;
            q.push(child);
        }
    }
    printf("%d\n", Node[maxn].level);
 
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int a,b;
        maxn = 1;
        //构建树
        for(int i=0 ; i<n-1; i++)
        {
            scanf("%d %d",&a, &b);
            maxn = max(a, b);
            Node[a].child.push_back(b);
        }
        layer();
        //层次遍历求高度
    }
 
    return 0;
}