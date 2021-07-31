/*
输入
        Cmax    <=100   油箱容量
        D   <=30000 目的地距离
        Davg    <=20    每升油可行驶距离
        N   <=500   加油站数
        N行     Pi 油价     Di  加油站距起点距离
输出
        无法到达终点，输出可到达最远距离，2位小数
        可到达终点，输出最便宜的方案的花销，2位小数
思路 
        将终点视为单位油价为0，距起点距离D的加油站，所有加油站按照距离排序
            起点没有加油站则无法出发，结束
        假设身处加油站now，从满油状态可及的加油站中选择下一个加油站，策略如下
            寻找比当前站更便宜的加油站k，加油使恰好到达k
            如果没有更便宜的，就找最便宜的那个，加满油到达k
            如果满油可及范围内无加油站，加满油结束


*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1000000000;

struct station{
    double p;
    double d;
}sta[505];

bool cmp(station a,station b){
    return a.d<b.d;
}

int main(){
    double Cmax,D,Davg;
    int N;
    while(cin>>Cmax>>D>>Davg>>N ){//输入相应参数
        for(int i=0;i<N;i++){
            cin>>sta[i].p>>sta[i].d;
        }
        sort(sta,sta+N,cmp);//排序
        sta[N].p=0;
        sta[N].d=D;

        if(sta[0].d!=0){
            cout<<"The maximum travel distance = 0.00"<<endl;
        }else{
            int now=0;//当前所处加油站
            double ans=0,nowTank=0,MAX=Cmax*Davg;//总花费、当前油量、满油行驶距离

            while(now<N){//开始循环，选择下一个加油站
                int k=-1;//最低油价的加油站编号
                double priceMin=INF;//最低油价
                //遍历满油可及站点
                for(int i=now+1;i<=N && sta[i].d-sta[now].d<=MAX;i++){
                    if(sta[i].p<priceMin){
                        priceMin=sta[i].p;
                        k=i;
                        if(priceMin<sta[now].p){//比当前加油站便宜，跳出循环，加油至刚好行驶到该站
                            break;
                        }
                    }
                }
                if(k==-1) break;// 表明无可及加油站，结束循环
                //根据上面找到的下一个站点k，计算花费
            //need，需要的油量
                double need=(sta[k].d-sta[now].d)/Davg;
                if(priceMin<sta[now].p){
                    if(nowTank<need){
                        ans+=(need-nowTank)*sta[now].p;
                        nowTank=0;
                    }else{
                        nowTank-=need;
                    }
                }else{
                    ans+=(Cmax-nowTank)*sta[now].p;
                    nowTank=Cmax-need;
                }
                now=k;//进入下一次循环
            }
            if(now==N){
                printf("%.2f\n",ans);
            }else{
                printf("The maximum travel distance = %.2f\n",sta[now].d+MAX);
            }

        }



    }
    return 0;

}
