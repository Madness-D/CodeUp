//A和B(<=2^31-1)，long long
#include<iostream>
using namespace std;

int main(){
    int m,num,ans[32];
    long long A,B;
    while(cin>>m && m){
        cin>>A>>B;
        num=0;
        A+=B;
        do{
           ans[num++]= A%m;
           A/=m;    
        }while(A!=0);
        for(int i=num-1;i>=0;i--){
            cout<<ans[i];
        }
        cout<<"\n";
    }

    return 0;
}
