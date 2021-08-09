/*
读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。
输入
    测试输入包含若干测试用例，每个测试用例占一行，每行不超过200个字符，
    整数和运算符之间用一个空格分隔。没有非法表达式。
    当一行中只有0时输入结束，相应的结果不要输出。
步骤
    中缀表达式转后缀表达式
        设立一个操作符栈，临时存放操作符
        设立一个数组或队列，存放后缀表达式
        从左至右扫描中缀表达式，碰到操作数就将其加入后缀表达式
        碰到操作符
    计算后缀表达式
*/


#include <cstdio>
#include <iostream> 
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node{
	
	double num;		//操作数 
	char op;		//操作符 
	bool flag;		//操作符为false,操作数为true	
}; 

string str;
stack<node> s;		//在change()存放操作符,在Cal()中存放操作数 
queue<node> q;		//存放后缀表达式的队列 
map<char,int> op;	//关于操作符的映射 

void Change(){		//中缀表达式转后缀表达式 
	
	double num;
	node temp;		
	
	for(int i=0; i<str.length(); ){
		
		if(str[i]>='0' && str[i]<= '9'){	//若是操作数 
			temp.flag = true;//标记是数字
			temp.num = str[i++] - '0';	//操作数可能不是个位数,因此要存储多位 
			while( i<str.length() && str[i] >='0' && str[i]<='9'){	
				temp.num = temp.num *10 + (str[i] - '0');	//若为十位以上,则将化为十进制 
				i++;										
			}
			q.push(temp);		//存入后缀表达式的队列中 
		}else {			//若是操作符 			
			temp.flag = false;	
            //比较当前操作符与栈顶的优先级,不大于的都弹出 		
			while(!s.empty() && op[str[i]] <= op[s.top().op]  ){	
				q.push(s.top());						//注:s.top()为node型, node.op == '+' 
				s.pop();
			}
			temp.op = str[i] ;		//将当前操作符 
			s.push(temp);			// 入栈
			i++;	
		}
	}
	
	while(!s.empty() ){			//若遍历完栈中还有操作符,全部弹出 
		q.push(s.top());
		s.pop();
	}
} 
	
double Cal(){			//计算后缀表达式 

	double x1,x2;
	node temp,cur;
	
	while(!q.empty()){

		cur = q.front();	//cur 记录队首 
		q.pop();			//出队列 
		if( cur.flag == true) 	s.push(cur);	//若为操作数,则入栈 
		else{		//若为操作符,则弹出2个操作数 
			
			x2 = s.top().num;	//先弹第2个数 
			s.pop();
			x1 = s.top().num;	//再弹第1个数,顺序不能乱 
			s.pop();
			
			temp.flag = true;		//临时记录一个操作数 
			if(cur.op == '+') temp.num = x1 + x2;
			else if(cur.op == '-') temp.num = x1- x2;
			else if(cur.op == '*' ) temp.num = x1 *x2;
			else if(cur.op == '/') temp.num = x1/x2;
			
			s.push(temp); 	 
			
		}
	}
	
	return s.top().num; 	//最后剩下的就是结果 
	
	
} 

int main(){
	
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;	
	
	while(getline(cin,str) , str !="0"){		//getline是获取一整行的字符串 
		
		string::iterator it ;
		for(it = str.end(); it != str.begin() ; it--){
			if(*it == ' ') 			//注意这是指针与int型的比较,不是" "
				str.erase(it);		//将字符串的空格全部清除 
		}
		
		while(!s.empty()) s.pop();	//初始化栈,避免栈不为空,留了东西 
		Change();

		printf("%.2lf\n" , Cal());
		 
		
	}
	
	return 0;
}
