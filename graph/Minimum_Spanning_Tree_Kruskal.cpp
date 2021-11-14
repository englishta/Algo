// 最小全域木　クラスカル法
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind{
	public:
	vector<ll> r;

	UnionFind(ll N){
		r = vector<ll>(N, -1);
	}

	ll root(ll x){
		if(r[x] < 0) return x;
		return r[x] = root(r[x]);
	}

	bool unit(ll x, ll y){
		x = root(x);
		y = root(y);
		if(x == y) return false;
		if(r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}

	ll size(ll x){
		return -r[root(x)];
	}

    bool same(ll x, ll y){
        return root(x) == root(y);
    }

};


struct Edge{
    ll from, to, cost;
    Edge(ll f, ll t, ll c): from(f), to(t), cost(c){}
    bool operator<(const Edge& other){
        return cost < other.cost;
    }
};

int main(){
    ll V, E;
    cin >> V >> E;
    UnionFind uf(V);
    vector<Edge> G;

    for(ll i=0; i<E; i++){
        ll f, t, c;
        cin >> f >> t >> c;
        G.emplace_back(f, t, c);
    }
    sort(G.begin(), G.end());
    ll w=0;
    for(auto &[f, t, cost] : G){
        if(uf.same(f, t)) continue;
        uf.unit(f, t);
        w+=cost;
    }
    cout << w << "\n";
    

    return 0;
}