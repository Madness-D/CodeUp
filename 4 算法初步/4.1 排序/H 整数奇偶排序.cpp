#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
    int temp,jn=0,on=0;
    int a[10],j[10],o[10];
    while(cin>>temp){
        if(temp%2!=0){
            j[jn]=temp;jn++;
        }else{
            o[on]=temp;on++;
        }
        if(jn+on==10){
            sort(j,j+jn,cmp);
			sort(o,o+on);
			for(int i=0;i<jn;i++){
				cout<<j[i]<<" ";
			}
			for(int i=0;i<on;i++){
				cout<<o[i]<<" ";
			}
			cout<<"\n";
            jn=on=0;

        }

    }
    return 0;
}