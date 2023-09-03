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
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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

const int MOD=998244353;

int main(){
    int N;
    cin>>N;
    vii cards(N,vi(2)) ,dp(N+1,vi(2,0));
    dp[0][0]=dp[0][1]=1;
    rep(i,N){
        cin>>cards[i][0]>>cards[i][1];
    }
    REP(i,1,N){
        rep(pre,2)rep(nxt,2){
            if(cards[i-1][pre]!=cards[i][nxt])dp[i][nxt]=(dp[i][nxt]+dp[i-1][pre])%MOD;
        }
    }
    cout<<(dp[N-1][0]+dp[N-1][1])%MOD<<endl;
    return 0;
}
/*

*/