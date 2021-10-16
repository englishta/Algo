#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = std::pair<ll, ll>;
#define rep(i,n) for(ll i=0; i<(n); i++)


// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja
// トポロジカルソート

int main() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> G(n);
    vector<ll> In(n);
    queue<ll> que; // 入次数が0の頂点の集合
    vector<ll> ans; // トポロジカルソートした順を記録する

    for(ll i=0; i<m; i++){
        ll a, b; cin >> a >> b;
        // a--; b--;
        G[a].push_back(b);
        In[b]++;
    }
    for(ll i=0; i<n; i++){
        if(In[i] == 0) que.push(i);
    }
    while(!que.empty()){
        ll v = que.front();
        ans.push_back(v);
        que.pop();
        for(auto nv : G[v]){
            In[nv]--;
            if(In[nv] == 0) que.push(nv);
        }
    }
    for(auto e : ans) cout << e << "\n";


    
    return 0;
}
