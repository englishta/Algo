// O(r+log(MOD))


long long MOD=1000000007;

//åJÇËï‘ÇµìÒèÊñ@
long long pow_mod(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n ÇÃç≈â∫à bitÇ™1Ç»ÇÁÇŒ(nÇ™äÔêîÇ»ÇÁÇŒ) x^(2^i) ÇÇ©ÇØÇÈ
        x = x * x % MOD;
        n >>= 1;  // n Ç1bit ç∂Ç…Ç∏ÇÁÇ∑
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