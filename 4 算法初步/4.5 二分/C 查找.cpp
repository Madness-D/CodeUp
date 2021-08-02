#include<iostream>
#include<algorithm>
using namespace std;

int erfen(int a[],int n,int x){//n为数组长度，x为要查找的元素
    int left=0,right=n-1,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(a[mid]==x) return mid;
        else if(a[mid]>x){right=mid-1;}
        else{left=mid+1;}
    }
    return -1;
}

int main() {
    int  n;
    while (cin >> n && n) {
        int a[105], m, target;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a,a+n);
        cin >> m;
        while (m--) {
            cin >> target;
            if (erfen(a, n, target) != -1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}