#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)

using Graph = vector<vector<ll>>;

int main(){
	ll n, m;
    cin >> n >> m;

	Graph G(n);
	rep(i,m){
        ll a, b;
        cin >> a >> b;
        a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	queue<ll> que;

    vector<ll> dist(n, -1);
    dist[0] = 0;
    que.push(0);

    while(!que.empty()){
        ll v = que.front();
        que.pop();

        for(ll nv : G[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    
    return 0;
}
