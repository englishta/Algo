#include <iostream>
using namespace std;

// 素数を判定する関数
bool isprime(long long N) {
    if (N < 2) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    // 入力
    long long N;
    cin >> N;

    // 判定
    if (isprime(N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}