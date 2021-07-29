#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct Student {
    char xuehao[100];
    char name[100];
    char sex[100];
    int age;
}stu[1000];

int main() {
    int N;
    while(scanf("%d",&N)!=EOF){
    for (int i = 0; i < N; i++) {
        cin >> stu[i].xuehao >> stu[i].name >> stu[i].sex >> stu[i].age;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int flag = 0;
        char obj[100];
        cin >> obj;
        for (int j = 0; j < N; j++) {
            if (!strcmp(obj,stu[j].xuehao) ){
                flag = 1;
                cout << stu[j].xuehao << " " << stu[j].name << " " << stu[j].sex << " " << stu[j].age << endl;
                break;
            }
        }
        if (!flag) {
            cout << "No Answer!\n";
        }
    }
    }
    return 0;

}