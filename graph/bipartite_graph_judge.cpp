#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 二部グラフ判定,N頂点M辺

vector<vector<ll>> G;
vector<ll> c; // -1, 1, 0:=色付けされてない
bool dfs(ll v, ll color){
    c[v] = color;
    for(auto nv : G[v]){
        if(c[nv] == color) return false;
        if(c[nv] == 0 && !dfs(nv, -color)) return false;
    }
    return true;
}

int main(){
    ll n, m; cin >> n >> m;
    G.resize(n);
    c.resize(n, 0);
    for(ll i=0; i<m; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bool ok = true;
    for(ll i=0; i<n; i++){
        if(c[i] == 0) ok &= dfs(i, 1);
    }
    cout << (ok? "Yes" : "No") << "\n";


    return 0;
}