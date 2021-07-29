#include<stdio.h>
#define MaxN 10
int main(){
    int n;//层数，<10
    int yh[MaxN][MaxN];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
		yh[i][0]=1;
		yh[i][i]=1;//杨辉三角形每行第一列和最后一列数据都为1 
		for(int j=1;j<i;j++)
		{
			yh[i][j]=yh[i-1][j-1]+yh[i-1][j];//每个数字等于肩上两数字之和 
		}
	}

    for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++)
		{
			printf("%d ",yh[i][j]);
		}
        printf("\n");
	}
return 0;
}