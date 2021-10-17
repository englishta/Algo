#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)


// テトリスの問題
// ICPC2014年,連鎖消滅パズル
// https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1193?year=2014

int main() {
   while(true){
      ll h; cin >> h;
      if(h == 0) break;
      ll w = 5, sequence = 3, score = 0;
      vector<vector<ll>> G(h, vector<ll>(5));
      rep(i,h){
         rep(j,w) cin >> G[i][j];
      }
      while(true){
         bool update = false;
         vector<vector<char>> check(h, vector<char>(5, 'o'));
         for(ll i=0; i<h; i++){
            ll left=0, right;
            while(left+1<w){
               ll c = G[i][left];
               right = left+1;
               ll cnt = 1;
               while(right<5 && c == G[i][right]){
                  if(c == -1) break;
                  cnt++;
                  right++;
               }
               if(cnt >= sequence){
                  for(ll j=left; j<right; j++){
                     check[i][j] = 'x';
                  }
                  score+=c*cnt;
                  update = true;
               }
               left = right;
            }
         }
         if(!update) break;
         // rep(i,h){
         //    rep(j,5) cout << check[i][j] << " ";
         //    cout << endl;
         // }
         for(ll j=0; j<5; j++){
            ll cnt_break=0;
            for(ll i=h-1; i>=0; i--){
               if(check[i][j] == 'x'){
                  cnt_break++;
                  G[i][j] = -1;
               }
               else{
                  G[i+cnt_break][j] = G[i][j];
                  if(cnt_break>0) G[i][j] = -1;
               }
            }
         }
         // rep(i,h){
         //    rep(j,5) cout << G[i][j] << " ";
         //    cout << "\n";
         // }
      }
      cout << score << "\n";

   }
   
   return 0;
}
