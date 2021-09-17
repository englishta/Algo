#include <iostream>
#include <vector>
using namespace std;

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (int p = 2; p*p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * p; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main() {
    // 入力
    int N;
    cin >> N;

    // エラトステネスの篩
    vector<bool> isprime = Eratosthenes(N);

    // 答え
    int res = 0;
    for (int i = 2; i <= N - i; ++i) {
        if (isprime[i] && isprime[N-i]) ++res;
    }
    cout << res << endl;
}