#include<cstdio>

int main(){
    int N;
    int cj[200];
    while(scanf("%d",&N)!=EOF && N){
        for(int i=0;i<N;i++){
            scanf("%d ",&cj[i]);
        }
        int obj,res=-1;
        scanf("%d",&obj);
        for(int i=0;i<N;i++){
            if(cj[i]==obj){res=i;break;}
        }
        printf("%d\n",res);
    }
    return 0;
}