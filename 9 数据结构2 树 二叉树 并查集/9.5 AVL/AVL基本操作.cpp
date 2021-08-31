#include<iostream>
#include<vector>
using namespace std;


struct node{
    int val,height;
    node* lchild;
    node* rchild;
};

node* newNode(int v){
    node* Node=new node;
    Node->val=v;
    Node->height=1;
    Node->lchild=Node->rchild=nullptr;
    return Node;
}

int getHeight(node* root){
    if(root==nullptr) return 0;
    else return root->height;
}

//计算平衡因子，左树高度-右树高度
int getBalanceFactor(node* root){
    return getHeight(root->lchild)-getHeight(root->rchild);
}
//更新height
void updateHeight(node* root){
    root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

//查找
void search(node* root,int x){
    if(root==nullptr){
        cout<<"0 ";
        //cout<<"search failed\n";
        return ;
    }
    if(x==root->val){
        //cout<<root->val<<'\n';
        cout<<"1 ";
    }else if(x<root->val){
        search(root->lchild,x);
    }else if(x>root->val){
        search(root->rchild,x);
    }
}

//插入
//左旋操作
void lrotation(node* &root){
    node* temp=root->rchild;//temp指向B
    root->rchild=temp->lchild;//步骤1，让b的左子树成为A的右子树
    temp->lchild=root;//步骤2，让A成为B的左子树
    updateHeight(root);
    updateHeight(temp);
    root=temp;//步骤3，将根节点设定为B
}
//右旋
void rrotation(node* &root){
    node* temp=root->lchild;//temp指向A
    root->lchild=temp->rchild;//步骤1
    temp->rchild=root;//步骤2
    updateHeight(root);
    updateHeight(temp);
    root=temp;//步骤3，将根节点设定为A
}
//插入之后，有些结点会失衡，度变为2或-2，需要调整
//只要把最靠近插入结点的失衡结点调整到正常，路径上的所有结点就会平衡
void insert(node* &root,int v){
    if(root==nullptr){
        root=newNode(v);
        return ;
    }
    if(v<root->val){
        insert(root->lchild,v);//插入
        updateHeight(root);//更新树高
        if(getBalanceFactor(root)==2){//
            if(getBalanceFactor(root->lchild)==1){//LL, rrotation
                rrotation(root);
            }else if(getBalanceFactor(root->lchild)==-1){//LR, 
                lrotation(root->lchild);
                rrotation(root);
            }
        }
    }else{
        insert(root->rchild,v);
        updateHeight(root);
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->rchild)==-1){//RR
            lrotation(root);
            }else if(getBalanceFactor(root->rchild)==1){//RL
            rrotation(root->rchild);
            lrotation(root);
            }
        }
    }
}

//AVL树的建立
node* create(vector<int> data,int n){
    node* root=nullptr;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> data(n);
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    node* root=create(data,n);
    int index;
    while(k--){
        cin>>index;
        search(root,index);
    }

    return 0;


}


