//大写：-32
#include<iostream>
#include<string>
using namespace std;

bool yes(char a) {
    if (a == ' ' || a == '\t' || a == '\r' || a == '\n') {
        return true;
    }
    else {
        return false;
    }

}

int main() {
    string a;
    while (getline(cin, a)) {
        if (a[0] <= 'z' && a[0]>='a') { a[0] -= 32; }
        int n = a.length();
        for (int i = 0; i < n; i++) {
            if (yes(a[i])&&a[i+1]<='z'&&a[i+1]>='a') {
                a[i + 1] -= 32;
            }
        }
        cout << a<<endl;
    }

    return 0;
}