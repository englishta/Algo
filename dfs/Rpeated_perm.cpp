#pragma region Macros
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(ll i, string s, string Elem, ll size, vector<string>& buf){
	if(i == size) buf.push_back(s);
	else for(auto e : Elem) dfs(i+1, s+e, Elem, size, buf);
}
vector<string> Repeated_Perm(string Elem, ll size){
    vector<string> buf;
    dfs(0, "", Elem, size, buf);
    return buf;
}

// 文字列Elemの要素からsize個選ぶ重複組み合わせ
// o(|Elem|^size)
int main(){
    auto x = Repeated_Perm("abcd", 3);
    for(auto e : x){
        cout << e << endl;
    }

    return 0;
}
