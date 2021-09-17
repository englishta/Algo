#include<bits/stdc++.h>
using namespace std;
using ll = long long;


// 整数xとyの最大公約数をユーグリッド互除法を用いて求める．

ll gcd(ll x, ll y) {
    if(x<y) swap(x, y);
    if(x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y); 
        //x%y==0でないときはユーグリットの互除法を使って再帰的に関数を呼び出す。
    }
}