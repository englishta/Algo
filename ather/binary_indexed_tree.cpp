#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)


// binary_indexed_tree
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp

/* BIT: 区間和の更新や計算を行う構造体
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(i,x): a_i += x とする
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    計算量は全て O(logn)
*/

template <typename T>
class BIT {
    public:
    int n;          // 配列の要素数(数列の要素数+1)
    vector<T> bit;  // データの格納先
    BIT(int n_) : n(n_ + 1), bit(n, 0) {}
    void add(int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }
    T sum(int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[idx];
        }
        return s;
    }
};


int main(){
    ll n, q;
    cin >> n >> q;
    BIT<ll> t(n);
    rep(i,q){
        ll c; cin >> c;
        if(c == 0){
            ll I, x; cin >> I >> x;
            t.add(I, x);
        }else{
            ll x, y; cin >> x >> y;
            cout << t.sum(y)-t.sum(x-1) << "\n";
        }
    }

	
    return 0;
}
