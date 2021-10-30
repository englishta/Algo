#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)


/* 
A ˆÈ‰º‚Ì”‚ª N ŒÂ—^‚¦‚ç‚ê‚éB‘S‚Ä‘fˆö”•ª‰ð‚¹‚æ
o(AloglogA+NlogA)
N=a.size()
A=max{a[0], a[1], ....a[N-1]}
*/
vector<vector<pair<ll, ll>>> f(vector<ll> a){
    ll Max = 0; // a‚ÌÅ‘å’l
    for(auto e : a) if(e>Max) Max = e;
    vector<ll> D(Max+1);
    D[1] = 1;
    for(ll p=2; p<=Max; p++){
        if(D[p]>0) continue;
        for(ll q=p; q<=Max; q+=p){
            D[q] = p;
        }
    }
    vector<vector<pair<ll, ll>>> v(a.size());
    for(ll i=0; i<a.size(); i++){
        ll k = a[i];
        if(k == 1){
            v[i].emplace_back(1, 1);
            continue;
        }
        while(k>1){
            ll p = D[k], cnt = 0;
            while(k%p == 0){
                cnt++;
                k/=p;
            }
            v[i].emplace_back(p, cnt);
        }
    }
    return v;
}

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    auto v = f(a);

    return 0;
}
