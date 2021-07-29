//输入两个字符串S1，S2；输出S1-S2
//input：They are students.
//          aeiou
//output:  Thy r stdnts.
//#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
//#include<fstream>
using namespace std;
char a[10010];//S1
char b[10010];//S2
int main() {
    //有空格，getline
	while(	cin.getline(a,10010)) {
		cin.getline(b,10010);
		int lena = strlen(a);
		int lenb = strlen(b);
		//如果两个for暴力搜索很慢，用hash
		bool test[10010] = {false};
		for(int i=0; i<lenb; i++) {
			test[b[i]] = true;
		}
		for(int i = 0; i < lena; i++) {
			if(test[a[i]]==false) {
				//printf("%c",a[i]);
                cout<<a[i];
			}
		}
		//printf("\n");
        cout<<"\n";
	}


	return 0;
    }