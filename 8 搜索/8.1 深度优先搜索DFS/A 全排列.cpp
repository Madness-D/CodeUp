#include<cstdio>
#include<iostream>
using namespace std;

int n;
int a[11];//存储全排列
bool hashtable[11]={0};//记录是否已经使用

void dfs(int step){
	if(step==n+1){//到达递归边界，输出
		//printf("%d",a[1]);
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
    
	for(int i=1;i<=n;i++){
		if(!hashtable[i]){
			hashtable[i]=true;
			a[step]=i;
			dfs(step+1);
			hashtable[i]=false; //这一步⭐，
		}
	}
}

int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
} 

