// n進数でnumと表記される数を，k進数に変換する
ll n_to_k(ll n, ll k, ll num){
    vector<ll> v;
    while(num>0){
        v.pb(num%10);
        num/=10;        
    }
    ll num10 = 0;
    ll e = 1;
    for(ll i=0; i<v.size(); i++){
        num10+=v[i]*e;
        e*=n;
    }
    vector<ll> t;
    while(num10>0){
        t.pb(num10%k);
        num10/=k;
    }
    ll ans = 0;
    ll keta = 10;
    reverse(all(t));
    rep(i,t.size()){
        ans+=t[i];
        if(i == t.size()-1) break;
        ans*=keta; 
    }
    return ans;
}