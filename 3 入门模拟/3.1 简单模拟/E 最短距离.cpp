#include<cstdio>
#define MaxN 100000

int main(){
    int n,sum=0;
    int N[MaxN];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&N[i]);
        sum+=N[i];
    }
    int m,o1,o2;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int d1=0,d2=0;
        scanf("%d %d",&o1,&o2);
        //保证o1<o2
        if(o1>o2){
            int temp=o1;
            o1=o2;
            o2=temp;
        }
        for(int i=(o1-1);i<o2-1;i++){
            d1+=N[i];
            }
            d2=sum-d1;
            printf("%d\n",d1<d2?d1:d2);

    }

    return 0;
}