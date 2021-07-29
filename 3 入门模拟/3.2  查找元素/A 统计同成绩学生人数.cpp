#include<cstdio>

int main(){
    int N;
    int cj[1000];
    while(scanf("%d",&N)!=EOF && N){
        for(int i=0;i<N;i++){
            scanf("%d ",&cj[i]);
        }
        int obj,res=0;
        scanf("%d",&obj);
        for(int i=0;i<N;i++){
            if(cj[i]==obj){res++;}
        }
        printf("%d\n",res);
    }
    return 0;
}