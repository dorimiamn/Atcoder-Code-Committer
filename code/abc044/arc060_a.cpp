/*
https://atcoder.jp/contests/abc044/submissions/4183707?lang=ja
勉強させていただいた提出
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()

ll N,A;
ll x[60];

//DP問題だった

int main(){
    cin>>N>>A;
    ll ANS=0;
    int X=A;
    rep(i,N){
        cin>>x[i];
        if(X<x[i])X=x[i];
    }

	vector< vector < vector<ll> > > dp(N+1, vector<vector<ll> >(N+1, vector<ll>(X*N+1)));

    rep(i,N+1){
        rep(j,N+1){
            rep(k,X*N+1){
                if(i==0&&j==0&&k==0)dp[i][j][k]=1;
                else if(i>=1&&k<x[i-1])dp[i][j][k]=dp[i-1][j][k];
                else if(i>=1&&j>=1&&k>=x[i-1])dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i-1]];
                else dp[i][j][k]=0;
            }
        }
    }
    REP(i,1,N+1){
        ANS+=dp[N][i][i*A];
    }
    cout<<ANS<<endl;

    return 0;
}
