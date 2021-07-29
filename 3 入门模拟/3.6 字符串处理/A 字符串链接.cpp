//不借用任何字符串库函数实现无冗余地接受两个字符串，然后把它们无冗余的连接起来。

#include<iostream>
using namespace std;

int main(){
    char a[100],b[100];

   while(cin >> a >> b) {
    char c[200];
    int flag = 0;
    for (int i = 0; i < 100; i++) {
        if (a[i] == '\0') {
            break;
        }
        c[i] = a[i];
        flag++;
    }
    int j = 0;
    for (; j < 100; j++) {
        if (b[j] == '\0') {
            break;
        }
        c[j + flag] = b[j];
        //flag++;如果在这里flag++，又因为j++，最后b的字符串是间隔存入c中
    }
    c[flag+j] = '\0';//注意字符串末尾的/0
    cout << c<<endl;//输出不换行，无法ac
    }
    return 0;
}