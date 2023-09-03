/*
https://drken1215.hatenablog.com/entry/2020/01/26/225000
勉強させていただいた記事
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

//制限がない時は小さくしていくことを考える

int main(){
    ll H,N;
    cin>>H>>N;
    vi A(N),B(N);
    rep(i,N)cin>>A[i]>>B[i];
    vii dp(N+1,vi(H+1,LongINF));
    rep(i,N)dp[i][0]=0;
    rep(i,N){
        rep(j,H+1){
            //使わない場合
            chmin(dp[i+1][j],dp[i][j]);
            //使う場合
            //遷移先より遷移元の方が小さかったら入れ替え
            chmin(dp[i+1][min(j+A[i],H)],dp[i+1][j]+B[i]);
        }
    }
    cout<<dp[N][H]<<endl;
    return 0;
}

//a=97,z=122