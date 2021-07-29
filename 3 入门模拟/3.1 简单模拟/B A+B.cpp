/*
给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。现在请计算A+B的结果，并以正常形式输出。
输入：
-234,567,890 123,456,789
1,234 2,345,678
输出：
-111111101
2346912
*/
#include<stdio.h>
#include<string.h>

//将字符串转换为整数，len为字符串长度
int trans(char str[12],int len){
    int sum=0;
    int n=1;//阶
    for(int i=len-1;i>=0;i--){//i=0
        if(str[i]<='9'&&str[i]>='0'){
            sum += n*(str[i]-'0');
            n *= 10;
        }
    }
    if(str[0]=='-'){
        sum=-sum;
    }
    return sum;
}

int main(){
char str1[15],str2[15];
while(scanf("%s %s",str1,str2)!=EOF){
    int len1=strlen(str1);
    int len2=strlen(str2);
    printf("%d\n",trans(str1,len1)+trans(str2,len2));
}
    return 0;
}
