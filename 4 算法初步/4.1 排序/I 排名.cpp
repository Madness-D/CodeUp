#include<iostream>
#include<algorithm>
#include<cstring>
using namespace  std;
struct student {
    char ID[25];
    int numbs;
    int solved[10];
    int finalscore = 0;
}stu[1000];

bool cmp(student stu1, student stu2) {
    if (stu1.finalscore != stu2.finalscore)
        return stu1.finalscore > stu2.finalscore;
    else
        return strcmp(stu1.ID, stu2.ID) < 0;
}
int main() {
    int N, M, G;
    int score[10];
    while (cin >> N >> M >> G && N) {
        for (int i = 0; i < M; i++)
            cin >> score[i];
        for (int i = 0; i < N; i++) {
            cin >> stu[i].ID >> stu[i].numbs;
            for (int j = 0; j < stu[i].numbs; j++) {
                cin >> stu[i].solved[j];
                stu[i].finalscore += score[stu[i].solved[j]-1];//注意-1
            }
        }
        sort(stu, stu + N, cmp);
        int stunum = 0;
        for (int i = 0; i < N; i++) {
            if (stu[i].finalscore >= G)
                stunum++;
        }
        cout << stunum << endl;
        for (int i = 0; i < stunum; i++) {
            cout << stu[i].ID << " " << stu[i].finalscore << endl;
        }


    }


    return 0;
}