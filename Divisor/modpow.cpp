#include<bits/stdc++.h>
using namespace std;
using ll = long long;


// modpow(m, n, mod)
// (m^n)%mod‚ð‹‚ß‚é
// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an
// AOJ https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll m, n; cin >> m >> n;
    cout << modpow(m, n, 1e9+7)) << "\n";


   return 0;
}
