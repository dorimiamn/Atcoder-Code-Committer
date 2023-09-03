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
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int mod=100000;

int DigitSum(int x){
    int ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return ans;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vi memo(mod);
    rep(i,mod){
        memo[i]=(i+DigitSum(i))%mod;
    }
    vi time_stamps(mod,-1);
    int pos=n,cnt=0;
    while(time_stamps[pos]==-1){
        time_stamps[pos]=cnt;
        pos=memo[pos];
        cnt++;
    }
    //time_stamps[pos]は一周するまでに必要な処理数,だからcntからこれを引くとサイクル数になるよね
    //posはnと等価
    int cycle=cnt-time_stamps[pos];
    if(k>=time_stamps[pos]){
        k=(k-time_stamps[pos])%cycle+time_stamps[pos];
        //kを1サイクルの中で考えたいので、一周するまでの処理数を一の除いて余りを取っている。
    }
    rep(i,mod){
        if(time_stamps[i]==k){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
/*
周期性はわかったが、
nから計算を始めて周期に入ったかを考える視点はなかった……
周期に入ったかどう求めらたらいいんだ？となっていたが理解。
周期に入るまでをkから差し引き、周期で余りを取る
実装が出来ない！
前計算してtime_stampsをO(1)で求めるのか
Kを余りで求めた後はNスタートも求めた数列を全部回して取るのか
idxを指定するするのかと思った
kは10**18で与えらえれていますね？long long だよ!
*/