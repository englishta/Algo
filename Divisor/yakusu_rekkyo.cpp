#include<bits/stdc++.h>
using namespace std;
using ll = long long;


set<ll> divisor(ll n){
    set<ll> st;
    for(ll i=1; i*i<=n; i++){
        if(n%i == 0){
            st.insert(n/i);
            st.insert(i);
        }
    }
    return st;
}

int main() {
    ll n; cin >> n;
    auto st = divisor(n);
    cout << st.size() << endl;
    return 0;
}