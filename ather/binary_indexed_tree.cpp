#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)


// binary_indexed_tree
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp

/* BIT: ��Ԙa�̍X�V��v�Z���s���\����
    �����l�� a_1 = a_2 = ... = a_n = 0
    �Eadd(i,x): a_i += x �Ƃ���
    �Esum(i): a_1 + a_2 + ... + a_i ���v�Z����
    �v�Z�ʂ͑S�� O(logn)
*/

template <typename T>
class BIT {
    public:
    int n;          // �z��̗v�f��(����̗v�f��+1)
    vector<T> bit;  // �f�[�^�̊i�[��
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
