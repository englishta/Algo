#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void chmin(ll &a, const ll &b){
    if (a>b) a = b;
}

int main() {
    string s, t;
    cin >> s >> t;
    ll slen = s.size(), tlen = t.size();
    ll INF = 101010;
    vector<vector<ll>> dp(slen+1, vector<ll>(tlen+1, INF));
    for(ll i=0; i<=slen; i++) dp[i][0] = i;
    for(ll j=0; j<=tlen; j++) dp[0][j] = j;
    for(ll i=1; i<=slen; i++){
        for(ll j=1; j<=tlen; j++){
            chmin(dp[i][j], dp[i-1][j]+1);            
            chmin(dp[i][j], dp[i][j-1]+1);            
            if(s[i-1] == t[j-1]) chmin(dp[i][j], dp[i-1][j-1]);
            else chmin(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    ll ans = dp[slen][tlen];
    cout << ans << endl;
    
    return 0;
}