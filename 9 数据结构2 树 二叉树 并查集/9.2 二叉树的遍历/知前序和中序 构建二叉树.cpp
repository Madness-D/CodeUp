//给定前序和中序，重新构建二叉树
//前序第一个元素是当前二叉树的根节点
//根节点在中序中将序列分为左树和右树
//递归构建二叉树
//递归边界，前序序列长度<=0


//参数：当前先序序列的区间[preL,preR],  中序序列区间[inL,inR]
node* creat(int preL,int preR,int inL,inR){
    if(preL>=preR){
        return nullptr;
    }

    node* root=new node;
    root->data=pre[preL];//pre序列

    int k;
    for(k=inL;k<=inR;k++){
        if(in[k]==pre[preL]){//在中序序列中找到根节点
            break;
        }
    }

    int numLeft=k-inL;

    //左树，先序区间[preL+1,preL+numLeft];中序区间[inL,k-1]
    //
    root->lchild=creat(preL+1,preL+numLeft,inL,k-1);

    root->rchild=creat(preL+numLeft+1,preP,k+1,inR);

    return root;

}

