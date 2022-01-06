#include<bits/stdc++.h>
using namespace std;


// a^{n} mod ‚ðŒvŽZ‚·‚é
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod ‚ðŒvŽZ‚·‚é
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}




