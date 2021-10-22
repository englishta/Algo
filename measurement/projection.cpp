#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 2021/10/22
// 2点a(x1, y1) b(x2, y2)を通る直線に，点p(x0, y0)から垂直に交わる直線を伸ばしたときの交点(X, Y)
// AOJ射影 https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A

pair<double, double> projection(double x1, double y1, double x2, double y2, double x0, double y0){
    if(y2-y1 == 0){
        return {x0, y1};
    }
    if(x2-x1 == 0){
        return {x1, y0};
    }
    double a = (y2-y1)/(x2-x1);
    double b = y1-a*x1;
    double d = y0+x0/a;
    double X = a*(d-b)/(a*a+1);
    double Y = a*X+b;
    return {X, Y};
}
int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll q; cin >> q;
    while(q--){
        double x0, y0; cin >> x0 >> y0;
        auto [X, Y] = projection(x1, y1, x2, y2, x0, y0);
        cout << setprecision(20) << fixed << X << " " << Y << "\n";
    }

    return 0;
}