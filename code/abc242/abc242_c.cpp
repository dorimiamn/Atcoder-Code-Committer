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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int mod=998244353;

int main(){
    int n;
    ll sum=0;
    cin>>n;
    vector<vector<ll>> dp(n+1,vector<ll>(9,0));
    rep(i,9){
        dp[0][i]=1;
    }
    rep(i,n){
        dp[i+1][0]=(dp[i][0]+dp[i][1])%mod;
        dp[i+1][1]=(dp[i][0]+dp[i][1]+dp[i][2])%mod;        
        dp[i+1][2]=(dp[i][1]+dp[i][2]+dp[i][3])%mod;
        dp[i+1][3]=(dp[i][2]+dp[i][3]+dp[i][4])%mod;
        dp[i+1][4]=(dp[i][3]+dp[i][4]+dp[i][5])%mod;
        dp[i+1][5]=(dp[i][4]+dp[i][5]+dp[i][6])%mod;
        dp[i+1][6]=(dp[i][5]+dp[i][6]+dp[i][7])%mod;
        dp[i+1][7]=(dp[i][6]+dp[i][7]+dp[i][8])%mod;
        dp[i+1][8]=(dp[i][7]+dp[i][8])%mod;
    }
    rep(i,9){
        sum=(sum+dp[n-1][i])%mod;
    }
    cout<<sum<<endl;
    return 0;
}
/*
dp?
dp[桁][数]
*/