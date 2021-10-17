#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// クラスの簡単な使い方

class hoge{
    public:
    string name;
    ll num, N;
    vector<ll> v;
    hoge(string name_, ll num_, ll N_) : name(name_), num(num_), N(N_) {
        v.resize(N);
        for(ll i=0; i<N; i++){
            v[i] = i*i;
        }
    }
};

int main() {
    hoge a("Tom", 1024, 10);
    cout << a.v[4] << "\n";


    return 0;
}