//规定哈弗曼树的左子树编码为0，右子树编码为1；
//若两个字符权值相同，则ASCII码值小的字符为左孩子，大的为右孩子；
//创建的新节点所代表的字符与它的做孩子的字符相同；
//所有字符为ASCII码表上32-96之间的字符（即“ ”到“`”之间的字符）。

//https://blog.csdn.net/changer_WE/article/details/88257385

/*
	最坑的地方在于输入有空格，导致c++那套输入流不好用，用的是c语言的scanf
	开头处加入忽略安全警告的声明 _CRT_SECURE_NO_WARNINGS
	此代码没有使用优先级队列，只是普通huffman编码的一点改动
		n个结点的满二叉树（全部塞满）叶子结点数为（n+1)/2，所以n个叶子节点的总结点数为2*n-1
		所以给哈夫曼树开空间就可以依照这个数（完全二叉树不满足这个性质）
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
 
#define N 200
 
struct Node{
	char ch;
	string huffman_str;//存储这个字符在树中的Huffman编码
	int weight;
	int left_child;
	int right_child;
	int parent;
};
 
void selectNode(int label, Node huff[200], int &node1, int &node2)	//选出两个权值最小的结点node1，node2
{
	int i = 0, min = -1;
	for (i = 0; i < label; i++)	//首先结点需要是没有父节点的,作为min的初始大小
	{
		if (huff[i].parent == -1)
		{
			min = i;
			break;
		}
	}
	for (i = 0; i < label; i++)	//找到第一小的结点
	{
		if (huff[i].parent == -1)
		{
			if (huff[i].weight < huff[min].weight)
				min = i;								//权值相等时，ASCII码值小的字符优先
			else if (huff[i].weight == huff[min].weight && huff[i].ch < huff[min].ch)
				min = i;
		}
	}
	node1 = min;	//现在min和node1记录的都是第一小的结点
 
	for (i = 0; i < label; i++)	//第二个min的初始大小
	{
		if (huff[i].parent == -1 && i != node1)
		{
			min = i;
			break;
		}
	}
	for (i = 0; i < label; i++)	//找到第二小的结点
	{							//有可能第二小的跟第一小的权值一样大，所以是小于等于	
		if (huff[i].parent == -1 && i != node1)
		{
			if (huff[i].weight < huff[min].weight)
				min = i;								//权值相等时，ASCII码值小的字符优先
			else if (huff[i].weight == huff[min].weight &&  huff[i].ch < huff[min].ch)
				min = i;
		}
	}
	node2 = min;
}
 
void createHuffmanTree(int n, Node huff[N])
{
	int node1 = -1, node2 = -1;
/*	if (n == 1)	//单独处理只有一个结点的情况
	{
		huff[1].left_child = 0;
		huff[0].parent = 1;
		huff[1].weight = huff[0].weight;
	}*/
	for (int i = n; i < 2 * n - 1; i++)	//最后只剩一棵树的时候停止，有n-1个非叶子结点，以此为结束条件
	{
		selectNode(i, huff, node1, node2);
		huff[i].ch = huff[node1].ch;//按照题目要求新树的字符等于左孩子的字符
		huff[i].left_child = node1;	//左子树的权值小，右子树权值大
		huff[i].right_child = node2;
		huff[i].weight = huff[node1].weight + huff[node2].weight;
		huff[node1].parent = i;	//合并成为一棵树，同一个父结点
		huff[node2].parent = i;
	}
}
 
void searchHuffmanCode(int n, Node huff[N])	//寻找哈夫曼编码
{
	int p, temp;
	for (int i = 0; i < n; i++)	//下标小于n的才是叶子节点
	{
		temp = i;	//用来判断是左儿子还是右儿子
		p = huff[i].parent;
		while (p != -1)
		{
			if (huff[p].left_child == temp)	//由于是从叶子出发到根，所以要使用插入函数
				huff[i].huffman_str.insert(0, "0");
			else
				huff[i].huffman_str.insert(0, "1");
			temp = p;
			p = huff[p].parent;
		}
		cout << huff[i].ch << ":" << huff[i].huffman_str << endl;	//在这输出
	}
}
 
int main()
{
	int n;	//最大为100组
	while (scanf("%d",&n) != EOF)//因为输入中含有空格，cin无法自动处理，真坑
	{
		getchar();	//作用是吞掉回车
		if (n == 0)	//n为0则跳出此次循环
			continue;
		Node huff[N];	//先假设最大是200个结点（题上没给）
		for (int i = 0; i < 2 * n; i++)	//可能用到的下标都初始化一下
		{
			huff[i].huffman_str = "";
			huff[i].parent = -1;
			huff[i].left_child = -1;
			huff[i].right_child = -1;
			huff[i].weight = 0;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%c%d", &huff[i].ch, &huff[i].weight);
			getchar();	//吞掉回车
		}
		createHuffmanTree(n, huff);
		/*for (int i = 0; i < 2 * n - 1; i++)	//输出测试
			cout << huff[i].parent << huff[i].left_child << huff[i].right_child << endl;
			*/
		searchHuffmanCode(n, huff);
	}
	return 0;
}