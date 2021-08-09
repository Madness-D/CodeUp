#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<queue>


using namespace std;

//任务结构体定义 
struct task{
    //任务名字 
    string name;
    //任务优先数 
    int priority;
    //比较符号小于的重载,以便用于优先队列使用 
    friend bool operator < (task a, task b){
        //首先按照优先数越小的排在前面，其次按照名字的字典序排序 
        if(a.priority != b.priority)
            return a.priority > b.priority;
        else
            return a.name > b.name;
    }
};
//处理一个任务调度序列
//参数s为当前输入的一个调度序列，pq为优先队列，have为map序列，其中存储了已经处理过的任务 
void load(string s, priority_queue<task> &pq, map<string, int> &have){
    string word = "";
    task t;
    //从0位置找到左括号，这个任务为当前输入的前序任务，后面括号中为后续任务 
    for(int i = 0; s[i] != '('; i++)
        word += s[i];
    //如果这个前序任务在have不存在，说明第一次出现，将其优先数定义为1
    //优先数越低表示优先级越高，这样定义是因为可由优先数从低到高累加，
    //如果定义为优先数越大优先级越高，首先问题就是不知道到底有多少个任务，因此不知定义最大优先数为多少合适 
    if(have[word] == 0){
        //第一次出现则记录该任务并初始化其优先数为最低即优先级最大 
        t.name = word;
        t.priority = 1;
        //在map序列中做记录，该任务已经存在 
        have[word] = t.priority;
        //加入优先队列 
        pq.push(t);
    }
    //删除左括号及以前的字符串 
    s.erase(s.begin(), s.begin()+s.find("(")+1);
    //处理后续任务，他们都是需要前序任务完成才能执行，因此他们的优先级也只比前序任务少一个级别
    //因此将前序任务word的优先数加1（优先级则降低,temp存储）作为后续的任务的优先数
    int temp = have[word] + 1;
    //重复使用word 
    word = "";
    for(int i = 0; i < s.size(); i++){
        //如果出现逗号或者右括号，表面又统计了一个任务，如果这个任务不是NULL并且是第一次出现就进行处理 
        if((s[i] == ',' || s[i] == ')') && (word != "NULL" && have[word] == 0)){
            //处理方式和前面相同 
            t.name = word;
            t.priority = temp;
            have[word] = t.priority;
            pq.push(t);
            word = "";
        }
        //没出现逗号之类则累加到当前单词上 
        else
            word += s[i];
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        //定义一个优先队列，存储调度的任务 
        priority_queue<task> pq;
        //map序列，存放已经存在的任务(键)及其对应的优先级(值)
        //map的定义主要用于判断一个任务是否是第一次出现，由于map不存在某个键的值时，该键的默认值时0
        //因此可通过判断其对应的值是否为0来判断一个任务是否第一次出现 
        map<string, int> have;
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            load(s, pq, have);
        }
        //任务序列输出 
        while(!pq.empty()){
            cout << pq.top().name;
            if(pq.size() > 1)
                cout << " ";
            else
                cout << endl;
            pq.pop();
        }
    }
    return 0;
}
