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
    ll N;
    cin>>N;
    vector<int> K(N);
    rep(i,N)cin>>K[i];
    vector<vector<ll> >dp(N,vector<ll>(21,0));
    dp[0][K[0]]=1;
    for(int i=1;i<N-1;i++){
        for(int j=0;j<=20;j++){
            if(j-K[i]>=0)dp[i][j]+=dp[i-1][j-K[i]];
            if(j+K[i]<=20)dp[i][j]+=dp[i-1][j+K[i]];
        }
    }

    cout<<dp[N-2][K[N-1]]<<endl;
    return 0;
}

//a=97,z=122