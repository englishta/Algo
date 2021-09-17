#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量, o(nloglogn)
int main() {
	ll n;
	cin >> n;
	vector<ll> v(n+1);
	for(ll i=2; i*i<=n; i++){
		if(v[i]>0) continue;
		for(ll j=i*i; j<=n; j+=i){
			v[j]++;
		}
	}
	return 0;
}
