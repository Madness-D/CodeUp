#include<iostream>
#include<cmath>
#include<vector>
using namespace std;



int main() {
    int n, layer;
    vector<int> vec;
    while (cin >> n && n) {
        vec.resize(n);

        for (int i = 0; i < n; i++){
            cin >> vec[i];
        }
        cin >> layer;
        //int layer = (int)log2(m) + 1;
        //int maxlayer = (int)log2(n) + 1;

        int left=pow(2,layer-1)-1;
        int mayright=pow(2,layer)-2;
        int right=mayright<n-1?mayright:n-1;
        if(left>n-1){cout << "EMPTY\n" ; }
        else{
            for(int i=left;i<=right;i++){
                cout<<vec[i]<<" ";
            }
            cout<<'\n';
        }

        // if (layer > maxlayer) { cout << "EMPTY\n" ; }
        // if (layer == maxlayer) {
        //     for (int i = pow(2, layer - 1) - 1; i < n; i++) {
        //         cout << vec[i] << " ";
        //     }
        //     cout <<'\n';
        // }
        // else {
        //     for (int i = pow(2, layer - 1) - 1; i < pow(2, layer) - 2; i++) {
        //         cout << vec[i] << " ";
        //     }
        //     cout << '\n';
        // }

    }
    return 0;
}