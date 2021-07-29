#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//数组，分别存储每月天数
int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
				  {1,31,29,31,30,31,30,31,31,30,31,30,31}};

int main()
{
	int y1,y2,m1,m2,d1,d2,sum,temp,flag;
	int t1,t2;
	while(scanf("%d%d",&t1,&t2)!=EOF){
		sum=1;
		if(t1>t2)
			swap(t1,t2);
		y1=t1/10000;m1=t1%10000/100;d1=t1%100;
		y2=t2/10000;m2=t2%10000/100;d2=t2%100;
		while(!(y1==y2&&m1==m2&&d1==d2)){
			flag=0;
			if(y1%4==0&&y1%100!=0||y1%400==0)
				flag=1;
			d1++;
			if(d1==(month[flag][m1]+1)){
				d1=1;
				m1++;
			}
			if(m1==13){
				m1=1;
				y1++;
			}
			sum++;
		}
		cout <<sum<<endl;
	}
	return 0;
} 