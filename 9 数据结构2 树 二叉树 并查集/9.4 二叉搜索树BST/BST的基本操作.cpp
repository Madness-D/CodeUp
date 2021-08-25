#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define typename int


struct node{
    typename  data;
    node* lchild;
    node* rchild;
};

//新建结点
node* newNode(typename v){
    node* Node=new node;
    Node->data=v;
    Node->lchild=Node->rchild=nullptr;
    return Node;
}

node* search(node* root,typename x){//查找返回数据域为x的结点地址
    if(root == nullptr){
        cout<<"search failed\n";
        return nullptr;
    }

    if(x==root->data){
        cout<<root->data<<'\n';
        return root;
    }else if(x<root->data){
        search(root->lchild,x);
    }else{
        search(root->rchild,x);
    }

}

//插入
void insert( node* &root,typename x){
    if(root==nullptr){//找到插入位置
    root=newNode(x);
    //return root;
    }

    if(x==root->data){
        return;
    }else if( x<root->data){
        insert(root->lchild,x);
    }else{
        insert(root->rchild,x);
    }
}

node* creat(vector<typename> data){
    int n=data.size();
    node* root=nullptr;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

node* findMax (node* root){
    while(root->rchild!=nullptr){
        root=root->rchild;
    }
    return root;
}

node* findMin(node* root){
    while(root->lchild!=nullptr){
        root=root->lchild;
    }
    return root;
}

void deleteNode(node* &root,typename x){//删除值为x的结点
    if(root==nullptr) return;
    if(root->data ==x){//找到结点
        if(root->lchild==nullptr && root->lchild==nullptr){
            root=nullptr;
        }else if(root->lchild!=nullptr){//左子树非空，删除前驱
            node* pre=findMax(root->lchild);
            root->data=pre->data;
            deleteNode(root->lchild,pre->data);//?
        }else{
            node* next=findMin(root->rchild);
            root->data=next->data;
            deleteNode(root->rchild,next->data);
        }
    }else if(root->data>x){
        deleteNode(root->lchild,x);
    }else{
        deleteNode(root->rchild,x);
    }

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
    vector<int> tem={2,5,3,7,8,9};
    node* root=creat(tem);
    inorder(root);
    return 0;

}