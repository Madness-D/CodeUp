/*
输入
        非负整数    M拥有的猫粮数   N个房间
        N行     J[i]房间中的奖励数    F[i]房间需要的猫粮数
        -1 -1 输入终止
输出
        三位小数，可获得的最大JavaBeans数目
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct room{
    double j;
    double f;
    double z;//单位猫粮的收益
}roo[1010];

bool cmp(room a,room b){
    return a.z>b.z;
}

int main(){
    int m,n;
    while(cin>>m>>n && m!=-1 && n!=-1){
        for(int i=0;i<n;i++){
            cin>>roo[i].j>>roo[i].f;
            roo[i].z=roo[i].j/roo[i].f;
        }
        sort(roo,roo+n,cmp);
        double res=0;//记录最终结果
        for(int i=0;i<n;i++){
            if(m>0&&m<roo[i].f){
                res+=m*roo[i].z;
                m=0;//这一步无所谓
                break;
            }else{
                m-=roo[i].f;
                res+=roo[i].j;
            }
        }
        printf("%.3f\n",res);

    }
}