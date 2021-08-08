/*
找到输出一个字符串中出现次数最多的单词及出现次数，字母不区分大小写
单词由字母和数字组成，例如can1和can就不是一个单词
关键在于实现单词的分割
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

bool check(char c){//检查是否是构成单词的合法字符
    if(c>='0' && c<='9') return true;
    if(c>='a' && c<='z') return true;
    if(c>='A' && c<='Z') return true;
    return false;
}

int main(){
    map<string,int> res;//map
    string s1;
    getline(cin,s1);// 输入带空格的s1
    int i=0;
    while(i<s1.length()){
        string word;
        while(i<s1.length() && check(s1[i])){//合法字符
            if(s1[i]<='Z'&&s1[i]>='A'){
                s1[i]+=32;//大写切换为小写
            }
            word+=s1[i];
            i++;
        }
        if(word!=""){
            if(res.find(word)==res.end()) res[word]=1;
            else res[word]++;
        }
        while(i<s1.length() && !check(s1[i])){ //非法字符，跳过
            i++;
        }
    }
    string ans;
    int MAX=0;
    for(map<string,int>::iterator it=res.begin();it!=res.end();it++){
        if(it->second > MAX){
            MAX=it->second;
            ans=it->first;
        }
    }
    cout<<ans<<" "<<MAX<<endl;
    return 0;
}

