#include<bits/stdc++.h>
using namespace std;
using ll = long long;


// ����x��y�̍ő���񐔂����[�O���b�h�ݏ��@��p���ċ��߂�D

ll gcd(ll x, ll y) {
    if(x<y) swap(x, y);
    if(x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y); 
        //x%y==0�łȂ��Ƃ��̓��[�O���b�g�̌ݏ��@���g���čċA�I�Ɋ֐����Ăяo���B
    }
}