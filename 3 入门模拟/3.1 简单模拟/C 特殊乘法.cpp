/*
写个算法，对2个小于1000000000的输入，求结果。特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
输入：
24 65
42 66666
3 67
输出：
66
180
39
*/

#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    char aa[10],bb[10];//应该没有负数吧
    while(scanf("%s %s",aa,bb)!=EOF){
        int sum=0;
        for(int i=0;i<strlen(aa);i++){
            for(int j=0;j<strlen(bb);j++){
                sum+=(aa[i]-'0')*(bb[j]-'0');
            }
        }
        printf("%d\n",sum);
    }
return 0;
}

