//第一行输入一个数，为n，第二行输入n个数，这n个数中，如果偶数比奇数多，输出NO，否则输出YES。

#include<cstdio>

int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n){
        int ji=0,ou=0,num;
        for(int i=0;i<n;i++){
            scanf("%d",&num);
            if(num%2==0){
                ou++;
            }else{
                ji++;
            }
        }
        if(ou>ji){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }

    return 0;
}