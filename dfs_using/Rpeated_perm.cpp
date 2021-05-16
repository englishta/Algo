#pragma region Macros
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(ll i, string s, ll start, ll end, ll size, vector<string>& buf){
	if(i == size){
        buf.push_back(s);
	}else{
		for(ll j = start; j<=end; ++j){
			dfs(i+1, s+char('0'+j), start, end, size, buf);
		}
	}
}
vector<string> Repeated_Perm(ll start, ll end, ll size){
// [start, end]からsize個選ぶ重複組み合わせ
// o((end-start+1)^size)
    vector<string> buf;
    dfs(0, "", start, end, size, buf);
    return buf;
}

int main(){
    // (1, 2, 3, 4, 5)->3つ選ぶ
    vector<string> x = Repeated_Perm(1, 5, 3);
    for(auto e : x){
        cout << e << endl;
    }

    return 0;
}
