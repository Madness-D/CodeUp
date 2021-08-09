/* 
输入
        包含多组测试数据。
        一个整数n（n<100000），表示有n个任务。
        接下来n行，每行第一个表示前序任务，括号中的任务为若干个后序任务，表示只有在前序任务完成的情况下，后序任务才能开始。若后序为NULL则表示无后继任务。
思路
        任务设置为一个结构体，用一个整数记录优先级
        设置一个优先队列，需要重载操作符设置优先级
        使用map进行string—>int的映射

 */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;

struct task{
    string name;
    int priority;
    bool operator <(const task &t)const{//重载运算符实现优先队列的优先级设置
        if(priority==t.priority) return name>t.name;//字典序小的在顶堆
        else return priority>t.priority;//重载<，priority小的在顶堆
    }
};
//string->int映射
map<string,int> mp;
//优先队列
priority_queue<task> q;

//输入
void deal(const string &str){
    task tmp;
    tmp.name=str.substr(0,5);
    if(str[6]!='N'){//如果有后续任务
        int idx=5;
        while(str[idx]!=')'){
            idx++;
            mp[str.substr(idx,5)]++;//idx
            idx+=5;
        }
    }
    else{//如果没有后续任务
    }
    tmp.priority=mp[tmp.name];
    q.push(tmp);
}

int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        deal(str);
    }
    
    int len=q.size(); 
    for(int i=0;i<len;i++){
        string tmp;
        tmp=q.top().name;
        q.pop();
        if(i<len-1) printf("%s ",tmp.c_str());
        else printf("%s",tmp.c_str());
    }

}