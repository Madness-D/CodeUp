//三个字符串 输出最大的那个
#include <stdio.h>
#include <string.h>
int main()
{
	char a[20],b[20],c[20];
	char *max;
	
	//两种c语言字符数输入方式 
	gets(a);
	scanf("%s",&b);
	//getchar();
	gets(c);
	
	//找出a b最大者 
	if(strcmp(a,b)>0)
		max = a;
	else
		max =b;
	
	if(strcmp(max,c)>0)
		puts(max);
	else
		puts(c);
	return 0;
}