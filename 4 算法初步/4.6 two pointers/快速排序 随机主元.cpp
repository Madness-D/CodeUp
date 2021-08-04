#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int Partition(int res[], int i, int j) { 
    int left = i, right = j;
    int p=(rand()%(right-left+1))+left;
    swap(res[p],res[left]);
    while(left < right)
    {
        while(left < right && res[i] <= res[right])
            right --;
        while(left < right && res[i] > res[left])
            left ++;
        swap(res[left], res[right]);
    }
    swap(res[i], res[left]);
    return left;
}

void qsort(int A[], int left, int right) {
    if (left < right) {
        int pos = Partition(A, left, right);
        qsort(A, left, pos - 1);
        qsort(A, pos + 1, right);
    }
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    int a[5050];
    cin >> n;
    for (int i = 0; i < n; i++)
            cin >> a[i];
     qsort(a, 0, n-1);
    for (int i = 0; i < n; i++)
            cout << a[i] << "\n";
    
    return 0;
}