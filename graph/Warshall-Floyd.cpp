#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// ワーシャルフロイド法
// ABC208-D
// https://atcoder.jp/contests/abc208/tasks/abc208_d
// 有効グラフ，0インデックス

int main(){
    ll n, m;
    cin >> n >> m;
    ll inf = 101010100000000;
    vector<vector<ll>> d(n, vector<ll>(n, inf));
    for(ll i=0; i<n; i++) d[i][i] = 0;
    for(ll i=0; i<m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
    }
    ll w = 0;
    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                if(d[i][j] != inf) w+=d[i][j];
            }
        }
    }
    cout << w << "\n";
    return 0;
}