/*
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
*/

#include<cstdio>

int main(){
    int N,num;
    while(scanf("%d",&N)!=EOF){
    int  flag,A1=0,A2=0,A3=0,A5=0;
    double A4=0.0;
    int A1f=0,A2f=0,A4f=0;//flag,输出N
    double A4sum=0.0;//定义为int 强制转化时丢失小数
    int sign=1;//A2
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        flag=num%5;
        switch(flag){
            case 0:
                if(num%2==0){ 
                    A1f=1;A1+=num;
                    }
                break;
            case 1:
                A2f=1;
                A2+=sign*num;
                sign *= -1;
                break;
            case 2:A3++;break;
            case 3:A4f++;A4sum+=num;A4=A4sum/A4f;break;
            case 4:if(A5<num){A5=num;}break;
        }
    }
    if(A1f){
        printf("%d ",A1);
    }else{printf("N ");}
    if(A2f){
        printf("%d ",A2);
    }else{printf("N ");}
    if(A3){
        printf("%d ",A3);
    }else{printf("N ");}
    if(A4f){
        printf("%.1f ",A4);
    }else{printf("N ");}
    if(A5){
        printf("%d",A5);
    }else{printf("N");}
    }
return 0;

}