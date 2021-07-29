#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int a[1000];
        //输入
        for (int i = 0; i < n; i++) { cin >> a[i]; }
        if(n==1){
            cout<<a[0]<<endl;
            cout<<-1<<endl;
        }
        else{
        //遍历找最大值的下标
        int maxIndex=0;
        for(int i=0;i<n;i++){
            if(a[i]>a[maxIndex]){
                maxIndex=i;
            }
        }
        //输出最大值
        cout<<a[maxIndex]<<endl;
        //剔除最大值
        for(int j=maxIndex;j<n-1;j++){
            a[j]=a[j+1];
        }
        //排序
        sort(a,a+n-1);
        //输出排序后的数组
        for (int i = 0; i < n-1; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        }
    }
    return 0;
}