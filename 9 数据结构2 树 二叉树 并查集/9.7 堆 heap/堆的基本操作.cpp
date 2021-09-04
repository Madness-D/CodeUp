#include<iostream>
using namespace std;

const int maxn = 100;
//heap为堆，n为元素个数
//使用数组存储树，对于结点i，2i为左孩子，2i+1为右孩子
int heap[maxn], n = 0;

//调整范围[low，high]；low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {//左子结点存在
        if (j + 1 <= high && heap[j + 1] > heap[j]) {
            j = j + 1;//令j为左右子结点中大的那一个的数组下标
        }
        if (heap[j] < heap[i]) {//子结点比根节点大，需要调整
            swap(heap[j], heap[i]);
            i = j;//接下来继续调整
            j = i * 2;
        }
        else {
            break;
        }
    }
}
void creatHeap() {
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}
void deleteTop() {
    heap[1] = heap[n--];
    downAdjust(1, n);
}
// 向上调整，把欲调整结点和父亲节点比较，交换
// 反复比较直到到达堆顶或父亲节点的权值较大
void upAdjust(int low, int high) {
    int i = high, j = i / 2;//j为父亲
    while (j >= low) {
        if (heap[j] < heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        }
        else { break; }
    }
}
void insert(int x) {
    heap[++n] = x;
    upAdjust(1, n);
}

int main() {
    int a[11] = { 2,4,6,1,23,7,8,3,5,0,9 };
    for (int i = 0; i < 11; i++) {
        insert(a[i]);
    }


    return 0;

}