#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;

    for(ll bit=0; bit<(1<<n); bit++){
        for(ll i=0; i<n; i++){
            if(bit & (1<<i)){
                //flag_stand_do
            }
        }
    }

    return 0;
}
