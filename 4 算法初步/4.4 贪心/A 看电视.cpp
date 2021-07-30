/*输入：
    整数n，n<=100,表示共n个节目
    n行，两个整数si，ei，开始时间 结束时间
    n=0，输入结束
    输出：能够 完整看的节目个数
思路：本质上就是一个不相交区间问题
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=110;
struct Inteval{
    int x,y;
}I[maxn];

bool cmp(Inteval a,Inteval b){
    if(a.x!=b.x) return a.x>b.x;//先按左端点从大到小排列
    else return a.y<b.y;//左端点相同的，按右端点从小到大排列
}

int main(){
    int n;
    while(cin>>n && n){
        for(int i=0;i<n;i++){
            cin>>I[i].x>>I[i].y;
        }
        sort(I,I+n,cmp);// 把区间排序
        //ans记录不相交区间个数，lastX记录上一个被选中 区间左端点
        int ans=1,lastX=I[0].x;
        for(int i=1;i<n;i++){
            if(I[i].y<=lastX){//不相交
                lastX=I[i].x;
                ans++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}

