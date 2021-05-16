#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[100][100];// メモ化再帰
ll cmb(ll n, ll r){
    if(r == 0 || r == n) return 1;
    if(memo[n][r] > 0) return memo[n][r];
    r = min(r, n-r);
    return memo[n][r] = cmb(n-1, r)+cmb(n-1, r-1);
}
int main(){
    cout << cmb(9, 3) << endl;
    return 0;
}
