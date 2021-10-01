#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = std::pair<ll, ll>;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

/* �O���b�h�̕��D��T�� */

// ABC151-D Maze Maxter  https://atcoder.jp/contests/abc151/tasks/abc151_d
// '.'�Ȃ�i�߂�C'#'�͏�Q��
// quene�̗v�f�̓^�v���^��{�c���W�C�����W�C�X�^�[�g�n�_����̋���or�ړ���}
// solve�֐��́C�O���b�h��T��������́C�ł����������n�_�܂ł̋�����Ԃ�
// solve�֐��̈����́Csolve(�X�^�[�g��i���W�C�X�^�[�g��j���W)

ll h, w;
vector<string> v;
int dj[4] = {1, -1, 0, 0};
int di[4] = {0, 0, 1, -1};

bool inside(ll I, ll J){
    if(I>=0 && I<h && J>=0 && J<w) return true;
    else return false;
}

ll solve(ll start_i, ll start_j){
    queue<tuple<ll, ll, ll>> Q;
    vector<vector<bool>> visit(h, vector<bool>(w, false));
    Q.push({start_i, start_j, 0ll});
    visit[start_i][start_j] = true;
    ll Max_dist = -1;
    while(!Q.empty()){
        auto [now_I, now_J, dist] = Q.front();
        if(dist>Max_dist) Max_dist = dist;
        Q.pop();
        for(ll i=0; i<4; i++){
            ll NI = now_I+di[i];
            ll NJ = now_J+dj[i];
            if(!inside(NI, NJ)) continue;
            if(visit[NI][NJ] || v[NI][NJ] == '#') continue;
            visit[NI][NJ] = true;
            Q.push({NI, NJ, dist+1});
        }
    }
    return Max_dist;
}

int main() {
    cin >> h >> w;
    v.resize(h);
    ll ans = -1;
    rep(i,h) cin >> v[i];
    for(ll i=0; i<h; i++){
        for(ll j=0; j<w; j++){
            if(v[i][j] == '#') continue;
            ll d = solve(i, j);
            if(d>ans) ans = d;
        }
    }
    cout << ans << "\n";
    return 0;
}