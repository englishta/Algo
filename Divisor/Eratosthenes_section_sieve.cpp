#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = std::pair<ll, ll>;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))

vector<bool> Eratos(ll a, ll b){
    vector<bool> v(b-a+1, true);
    vector<bool> table(10000000, true);
    table[1] = false; table[0] = false;
    for(ll p=2; p*p<=b; p++){
        if(table[p] == false) continue;
        for(ll j=p*2; j*j<=b; j+=p){
            table[j] = false;
        }
        ll q = (a+p-1)/p*p;
        ll start;
        if(q == p) start = 2*q;
        else start = q;
        for(ll i=start; i<=b; i+=p){
            v[i-a] = false;
        }
    }
    return v;
}

int main() {
    ll a, b; cin >> a >> b;
    auto v = Eratos(a, b);
    ll cnt = 0;
    for(ll i=a; i<=b; i++){
        if(v[i-a]) cnt++;
    }
    // for(auto e : v) cout << e << endl;
    cout << cnt << "\n";

    return 0;
}

