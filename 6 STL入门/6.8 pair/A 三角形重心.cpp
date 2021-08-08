#include<utility>
#include<iostream>
#include<cstdio>
using namespace std;

struct trian {
    pair<double, double>p1;
    pair<double, double>p2;
    pair<double, double>p3;
    double x;
    double y;
};

void func(trian & t) {
    t.x = (t.p1.first + t.p2.first + t.p3.first) / 3.0;
    t.y = (t.p1.second + t.p2.second + t.p3.second) / 3.0;
}

int main() {
    int n;
    while (cin >> n && n) {
        while (n--) {
            trian t;
            cin >> t.p1.first >> t.p1.second >> t.p2.first >> t.p2.second >> t.p3.first >> t.p3.second;
            func(t);
            printf("%.1f %.1f\n", t.x, t.y);
        }
    }
    return 0;
}
