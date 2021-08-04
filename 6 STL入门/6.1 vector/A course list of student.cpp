/*
学生姓名：三个大写字母+数字     提示：hash
*/
//使用cin cout会提示时间超限，需使用printf

#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int N=40010;
const int M=26*26*26*10+1;
vector<int> res[M];//二维数组
//将字符串转换为数字ID
int getID(char name[]){
    int id=0;
    for(int i=0;i<3;i++){//前三位字母转换为数字
        id=id*26+(name[i]-'A');
    }
    id=id*10+(name[3]-'0');//将最后一位数字添加到id最后
    return id;
}

int main(){
    int n,k;//n个学生，k门课程，课程用数字表示，学生用姓名字符串表示
    char name[5];
    //cin>>n>>k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++){
        int course,num;
        //cin>>course>>num;
        scanf("%d %d",&course,&num);
        for(int j=0;j<num;j++){
            //cin>>name;
            scanf("%s",name);
            int id=getID(name);
            //res[id][0]++;
            //res[id][course]=1;
            res[id].push_back(course);
        }
    }

    for(int i=0;i<n;i++){
        //cin>>name;
        scanf("%s",name);
        int id=getID(name);
        sort(res[id].begin(),res[id].end());
        //cout<<name<<" "<<res[id].size()<<" ";
        printf("%s %d ",name,res[id].size());
        for(int j=0;j<res[id].size();j++){
            //cout<<res[id][j]<<" ";
            printf("%d ",res[id][j]);
        }
        //cout<<endl;
        printf("\n");

}
return 0;


}