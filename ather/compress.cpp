#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
vector<T> compress(vector<T> X){
    ll n = X.size();
    vector<T> U = X, ans(n);
    sort(U.begin(), U.end());
    U.erase(unique(U.begin(), U.end()), U.end());
    for(ll i=0; i<n; i++){
        ans[i]=distance((U).begin(), lower_bound(U.begin(), U.end(), X[i]));
    }
    return ans;
}

vector<ll> compress(vector<ll> arr){
    ll n=arr.size();
    map<ll,ll> m;
    for(int i=0;i<n;i++){
        m[arr[i]]=0;
    }
    ll s=0;
    for(auto& i:m){
        i.second=s++;
    }
    vector<ll> ans;
    for(int i=0;i<n;i++){
        ans.push_back(m[arr[i]]);
    }
    return ans;
}

