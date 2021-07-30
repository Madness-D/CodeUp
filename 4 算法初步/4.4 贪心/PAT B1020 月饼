#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct mooncake{
    double store;
    double totalvalue;
    double price;
}cake[1010];

bool cmp(mooncake m,mooncake n){
    return m.price>n.price;
}


int main(){
    int n;//种类数
    double d;//需求
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>cake[i].store;
    }
    for(int i=0;i<n;i++){
        cin>>cake[i].totalvalue;
        cake[i].price=cake[i].totalvalue/cake[i].store;
    }
    sort(cake,cake+n,cmp);
    double interest=0;
    for(int i=0;i<n;i++){
        if(d>=cake[i].store){
            interest+= cake[i].totalvalue;
            d-=cake[i].store;
        }else{
            interest+= d*cake[i].price;
            break;
        }
    }
    printf("%.2f\n",interest);
    return 0;

}
