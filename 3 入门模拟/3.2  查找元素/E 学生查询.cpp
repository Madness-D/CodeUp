#include<iostream>
#include<cstring>
using namespace  std;

struct Student {
    char xuehao[100];
    char name[100];
    char sex[100];
    int age;
}stu[20];

int main() {
    int m;
    cin >> m;
    while(m--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> stu[i].xuehao >> stu[i].name >> stu[i].sex >> stu[i].age;
        }
            char obj[100];
            cin >> obj;
            for (int i = 0; i < n; i++) {
                if (!strcmp(obj, stu[i].xuehao)) {
                    cout << stu[i].xuehao << " " << stu[i].name << " " << stu[i].sex << " " << stu[i].age << endl;
                }
            }
        

    }
    return 0;


}