//https://qiita.com/drken/items/56a6b68edef8fc605821#%E5%95%8F%E9%A1%8C-3-atcoder-abc-122-c---get-ac
//参考にさせて頂いている記事
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll N,ANS=0;
    cin>>N;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    vector<ll> D(N+1,0);
    map<ll,ll> nums;
    for(ll i=0;i<N;i++){
        D[i+1]=D[i]+A[i];
    }
    for(int i=0;i<N+1;i++)nums[D[i]]++;

    //愚直にやるとTLEになるので、累積和の中からイコールとなるものを数え上げ、その組みが何通りあるかを数える。
    for(auto x:nums){
        ll n=x.second;
        ANS+=(n*(n-1))/2;
    }
    cout<<ANS<<endl;
    return 0;
}

//a=97,z=122