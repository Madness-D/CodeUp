/*
请写一个程序，判断给定表达式中的括号是否匹配，表达式中的合法括号为”(“, “)”, “[", "]“, “{“, ”}”,这三个括号可以按照任意的次序嵌套使用。
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool fun1(char a, char b) {
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '{' && b == '}')
        return true;
    else
        return false;
}

void fun2(string str) {
    int len = str.length();
    stack<char> st;
    bool flag = true;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {//左半边，入栈
            st.push(str[i]);
        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']') {//右半边，和栈中的元素比较匹配
            if (st.empty()) { // 栈空，无法匹配
                flag = false; break;
                 }
            else {
                flag = fun1(st.top(), str[i]);//返回匹配结果
                if (flag ) { //匹配得上，出栈
                    st.pop(); }
                if (!flag) { //匹配不上，后面的也就不用比了
                    break; }
            }
        }
    }

    if(!st.empty()){flag=false;}// 第一次未考虑到这种情况，如只输入[，这样的话经过上面的循环，flag仍为true
    if (!flag) { cout << "no\n"; }
    if (flag) { cout << "yes\n"; }
}

int main() {
    int n;
    while (cin >> n && n) {
        getchar();//如果没有这个，在输入n的时候也直接输出yes了
        while (n--) {
            string temp;
            getline(cin, temp);
            fun2(temp);
        }
    }
    return 0;
}