#include<iostream>
using namespace std;

int main() {
    int n;
    int money[5] = {50, 20, 10, 5, 1};
    while (cin >> n && n > 0) {
        int a[6] = { 0 };
        while (n > 0) {
            if (n >= 50) {
                n -= 50;
                a[0]++;
            }
            if (n < 50 && n >= 20) {
                n -= 20;
                a[1]++;
            }
            if (n < 20 && n >= 10) {
                n -= 10;
                a[2]++;
            }
            if (n < 10 && n >= 5) {
                n -= 5;
                a[3]++;
            }
            if (n < 5 && n>0) {
                n -= 1;
                a[4]++;
            }
        }
        // for (int i = 0; i < 5; i++)
        //     cout << a[i] << '\t';

        
        int count = 0;
        for(int i=0;i<=4;i++)
        {
            if(a[i]>0)
                count++;
        }
         for(int i=0;i<=4;i++)
        {
            if(a[i]>0)
            {
                if(count>1)
                    cout<<money[i]<<"*"<<a[i]<<"+";
                else
                    cout<<money[i]<<"*"<<a[i]<<endl;
                count--;
            }
 
        }

    }
    return 0;
}