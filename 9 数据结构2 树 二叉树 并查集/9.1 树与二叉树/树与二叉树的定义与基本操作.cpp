#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

#define typename int
struct node{
    typename data;
    node* lchild;
    node* rchild;
};

//新建节点
node* newNode(typename v){
    node* Node=new node;
    Node->data=v;
    Node->lchild=Node->rchild=nullptr;
    return Node;
}

//查找与修改
void search(node* root,typename x,typename newdata){
    if(root==nullptr){
        return;//到达边界叶节点
    }
    if(root->data==x){
        root->data=newdata;
    }
    search(root->lchild,x,newdata);
    search(root->rchild,x,newdata);
}

//节点插入
//注意是引用传递
void insert(node* &root, typename x){
    if(root==nullptr){
        root = newNode(x);
        return ;
    }
    if(判断条件，插入左子树){
        insert(root->lchild,x);
    }else{
        insert(root->rchild,x);
    }
}

//根据数组创建二叉树
node* Creat(typename data[],int n){
    node* root =nullptr;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

//前序遍历 
void preorder(node* root){
    if(root==nullptr){return;}
    cout<<root->data<<'\n';
    preorder(root->lchild);
    preorder(root->rchild);
}

//中序 遍历
void inorder(node* root){
    if(root==nullptr){return;}
    inorder(root->lchild);
    cout<<root->data<<'\n';
    inorder(root->rchild);
}

//后序遍历
void postorder(node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<'\n';
}

//层序遍历，bfs，队列 
void layerorder(node* root){
    queue<node*> q;//存地址的队列
    q.push(root);
    while(!q.empty()){
        node* now=q.front();
        q.pop();
        cout<<now->data<<'\n';
        if(now->lchild!=nullptr){q.push(now->lchild);}
        if(now->rchild!=nullptr){q.push(now->rchild);}
    }
}

int main(){
    node* root=nullptr;

    return 0;

}