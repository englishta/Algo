// O(r+log(MOD))


long long MOD=1000000007;

//繰り返し二乗法
long long pow_mod(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが1ならば(nが奇数ならば) x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}


long long nCr_mod(long long n, long long r) {
    long long x = 1, y = 1;

    for (int i = 0; i < r; i++) {
        x = x * (n - i) % MOD ;
        y = y * (i + 1) % MOD;
    }

    return x * pow_mod(y, MOD - 2) % MOD;
}