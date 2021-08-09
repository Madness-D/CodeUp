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
        if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (st.empty()) { flag = false; break; }
            else {
                flag = fun1(st.top(), str[i]);
                if (flag && !st.empty()) { st.pop(); }
                if (!flag) { break; }
            }

        }

    }
    if(!st.empty()){flag=false;}
    if (!flag) { cout << "no\n"; }
    if (flag) { cout << "yes\n"; }
}

int main() {
    int n;
    while (cin >> n && n) {
        getchar();
        while (n--) {
            string temp;
            getline(cin, temp);
            fun2(temp);
        }
    }
    return 0;
}