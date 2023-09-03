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
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

const ll mod=998244353;

template<class T>T modpow(T a,T n,T mod){
    ll res=1;
    while(n>0){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    if(k==0){
        cout<<modpow(m,n,mod)<<endl;
        return 0;
    }
    vii dp(n+1,vi(m+1,0));
    rep(i,m){
        dp[0][i]=1;
    }
    rep(i,n){
        vi sum(m+1,0);
        rep(j,m){
            //ここでも累積和を取る必要があるのでは
            sum[j+1]=(sum[j]+dp[i][j])%mod;
        }
        rep(j,m){
            if(j+k<=m)dp[i+1][j]=(dp[i+1][j]+sum[m]-sum[j+k]+mod)%mod;
            if(j-k+1>=0)dp[i+1][j]=(dp[i+1][j]+sum[j-k+1])%mod;
        }
    }
    ll ans=0;
    // rep(i,n+1){
    //     rep(j,m+1)cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    rep(i,m){
        ans=(ans+dp[n-1][i])%998244353;
    }
    cout<<ans<<endl;
    return 0;
}
/*
解説Submit
累積和を使えば,kで足す処理を 高速化出来る。
modの引き算の仕方が間違っていた?
*/