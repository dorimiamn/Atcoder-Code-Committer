#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll N,K;
    ll M=INF;
    cin>>N>>K;
    vector<int> H(N);
    rep(i,N)cin>>H[i];
    sort(H.begin(),H.end());
    for(int i=0;i<N-K+1;i++){
        if(M>H[i+K-1]-H[i])M=H[i+K-1]-H[i];
    }
    cout<<M<<endl;
    return 0;
}

//a=97,z=122