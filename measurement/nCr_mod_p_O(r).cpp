// O(r+log(MOD))


long long MOD=1000000007;

//�J��Ԃ����@
long long pow_mod(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n �̍ŉ���bit��1�Ȃ��(n����Ȃ��) x^(2^i) ��������
        x = x * x % MOD;
        n >>= 1;  // n ��1bit ���ɂ��炷
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