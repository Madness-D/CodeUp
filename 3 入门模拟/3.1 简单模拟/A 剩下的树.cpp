//有一个长度为整数L(1<=L<=10000)的马路，可以想象成数轴上长度为L的一个线段，起点是坐标原点，在每个整数坐标点有一棵树，即在0,1,2，...，L共L+1个位置上有L+1棵树。
//现在要移走一些树，移走的树的区间用一对数字表示，如 100 200表示移走从100到200之间（包括端点）所有的树。
//可能有M(1<=M<=100)个区间，区间之间可能有重叠。现在要求移走所有区间的树之后剩下的树的个数。
//思路：输入的移走区间，最小值min，最大值max，一共移走：max-min+1，剩余：L+1-（max-min+1）=L-max+min

#include<stdio.h>

int main(){
    int  L,M;
    while(scanf("%d %d",&L,&M)!=EOF,L||M){
        int a,b,max=-1,min=100000;
        for(int i=0;i<M;i++){
            scanf("%d %d",&a,&b);
            if(b>=max){
                max=b;
            }
            if(a<=min){
                min=a;
            }
        }
        printf("%d\n",L-max+min);
    }

    return 0;
}