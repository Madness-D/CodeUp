#include "cstdio"
#include "map"
#include "iostream"
#include "cctype"
#include "string"
using namespace std;
 
int main(){
	string s,t;
	getline(cin,s);
	map<string,int> cnt;
	for (int i=0;i<s.length();i++)
	{
		if (isalnum(s[i]))//合法字符
		{
			s[i]=tolower(s[i]);
			t+=s[i];//储存单词
		}
		if(!isalnum(s[i])||i == s.length() - 1){
			if(t.length() != 0) cnt[t]++;//储存了一个单词
			t = "";//t清空
		}
	}
	//寻找最多的那个
	int maxn=0;
	for (auto it=cnt.begin();it!=cnt.end();it++)
	{
		if (it->second>maxn)
		{
			maxn=it->second;
			t=it->first;
		}
	}
	cout<<t<<" "<<maxn<<endl;
	return 0;
}