bool isprime(int N) {
    if (N < 2) return false;
    for (int i = 2; i < N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}