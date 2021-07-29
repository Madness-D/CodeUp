//输入一个字符串，长度小于等于200，然后将输出按字符顺序升序排序后的字符串。
//注意输入的字符串中可能有空格。
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        sort(str.begin(),str.end());
        cout<<str<<endl;
    }
    return 0;
}

