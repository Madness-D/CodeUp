//两个链表按学号升序排列
#include<iostream>
#include<cstdio>
using namespace std;

struct node{
    int id;
    int score;
    node* next;
};

void insert( node* a,node* b){//将一个节点b插入链表a,按id排序
    node* pre;
    node* p;
    pre=a;
    p=a->next;
    while(p && p->id < b->id){
        pre=p;
        p=p->next;
    }
    pre->next=b;
    b->next=p;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    node *p,*pre,*a;
    a=new node;
    a->next=NULL;
//读取数据并按序插入链表a
	for(int i=0;i<n+m;i++){
		p=new node;
		p->next =NULL;
		scanf("%d %d",&p->id ,&p->score);
        insert(a,p);
	}
    //输出
    for(p=a->next ;p!=NULL;p=p->next){
    	printf("%d %d\n",p->id ,p->score );
    }
    return 0;
}