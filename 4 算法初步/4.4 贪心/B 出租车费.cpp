#include<iostream>
using namespace std;

double fee(double distance){
    double fee=0;
    if(distance<=4)
        fee=10;
    if(distance>4 && distance<=8)
        fee=10+2*(distance-4.0);
    if(distance>8){
        while(distance>=8){
            fee+=18;
            distance-=8;
        }
        if(distance <=4)
            fee+= 2.4*distance;
        else
            fee+=10+2*(distance-4.0);
    }
    return fee;
}

int main(){
    int n;
    while(cin>>n && n){
        if(fee(n)==(int)fee(n))
            printf("%f\n",fee(n));
        else    
            printf("%.1f\n",fee(n));
    }
    return 0;
}

