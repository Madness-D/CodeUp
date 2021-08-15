/*
实现链表的基本操作：查找元素、插入、删除
链表和顺序表相比的优势：适用于频繁插入和删除元素的情况，不必移动后面的元素
使用cin会导致超时
void creat 创建链表，用数组(逆序)初始化
void get 获取第a个元素 否则输出get fail
insert 在第a个位置插入元素e
delete 删除第a个元素
void show 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

typedef struct LNode
{
    int data;
    LNode * next;
}LNode, *LinkList;


bool InsertElem(LinkList &L,int loc,int e)
{
    LinkList ln = L;
    int i = 1;
    for (; i < loc && ln; ++i)
        ln = ln->next;

    if (!ln || i != loc)
        return false;

    LinkList tmp = new LNode;
    tmp->data = e;
    tmp->next = ln->next;
    ln->next = tmp;
    return true;
}


void CreateList(LinkList &L, int n)
{
    L = new LNode; L->next = NULL;
    for (int i = 0; i < n; ++i)
    {
        LinkList p = new LNode;
        scanf("%d", &(p->data));
        p->next = L->next;
        L ->next = p;
    }
}

bool DeleteElem(LinkList &L, int loc)
{
    int idx = 1;
    LinkList  p = L;
    while (p->next && idx < loc)
    {
        p = p->next;
        ++idx;
    }
    if (!(p->next) || idx != loc)
        return false;

    LinkList del = p->next;
    p->next = del->next;
    delete del;
    return true;
}

bool GetElem(const LinkList L, int loc,int & e)
{
    LinkList p = L;
    int idx = 0;
    while (p && idx < loc)
    {
        p = p->next;
        ++idx;
    }

    if (!p || idx != loc)
        return false;
    e = p->data;
    return true;
}

void PrintList(LinkList &L)
{
    LinkList p = L->next;
    if (!p)
    {
        printf("Link list is empty\n");
        return;
    }

    while (p)
    {
        printf("%d", p->data);
        p = p->next;
        if (p)
            printf(" ");
    }
    printf("\n");
}


enum INST {INSERT,GET,DELETE,SHOW,NONE};

INST instruction(char str[])
{
    if (strcmp(str, "show") == 0)
        return SHOW;
    if (strcmp(str, "delete") == 0)
        return DELETE;
    if (strcmp(str, "get") == 0)
        return GET;
    if (strcmp(str, "insert") == 0)
        return INSERT;

    return NONE;
}

int main()
{
#ifdef _DEBUG
    freopen("data.txt", "r+", stdin);
#endif // _DEBUG


    int N, loc, e;
    LinkList L = NULL;
    char inst[20];
    bool stat;

    scanf("%d",&N);

    CreateList(L, N);

    scanf("%d", &N);
    while (N--)
    {
        scanf("%s", inst);
        INST ins = instruction(inst);
        switch (ins)
        {
        case INSERT:
            scanf("%d %d", &loc, &e);
            stat = InsertElem(L, loc, e);
            if (stat)
                printf("insert OK\n");
            else printf("insert fail\n");
            break;
        case GET:
            scanf("%d", &loc);
            stat = GetElem(L, loc,e);
            if (stat)
                printf("%d\n", e);
            else printf("get fail\n");
            break;
        case DELETE:
            scanf("%d", &loc);
            stat = DeleteElem(L, loc);
            if (stat)
                printf("delete OK\n");
            else printf("delete fail\n");
            break;
        case SHOW:
            PrintList(L);
            break;
        case NONE:
            break;
        }
    }

    LinkList p = L, q;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    return 0;
}
/**************************************************************
    Problem: 1326
    User: Sharwen
    Language: C++
    Result: 升仙
    Time:22 ms
    Memory:2236 kb
****************************************************************/