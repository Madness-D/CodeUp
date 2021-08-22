//根据一个整数序列构造一个单链表，然后将其反转。
#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

int main(){
    int n;
    while(cin>>n){
        if(n==0){cout<<"list is empty\n";}
        ListNode* head=new ListNode;
        head->next=nullptr;
        
    }
}