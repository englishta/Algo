template<class T>
vector<T> compress(vector<T> &X){
    vector<T> Uni = X;
    sort(all(Uni));
    UNIQUE(Uni);
    for(ll i=0; i<(ll)X.size(); i++) X[i]=lb(Uni, X[i]);
    return X; 
}

vector<ll> compress(vector<ll> arr){
  ll n=arr.size();
  map<ll,ll> m;
  for(int i=0;i<n;i++){
    m[arr[i]]=0;
  }
  ll s=0;
  for(auto& i:m){
    i.second=s++;
  }
  vector<ll> ans;
  for(int i=0;i<n;i++){
    ans.push_back(m[arr[i]]);
  }
  return ans;
}

