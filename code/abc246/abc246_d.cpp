#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
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

ll calc(ll a,ll b){
    return a*a*a+a*a*b+a*b*b+b*b*b;
}

int main(){
    ll N,ans=LongINF;
    cin>>N;

    rep(i,1000001){
        ll ng=-1,ok=1000001;
        while(ok-ng>1){
            ll mid=(ok+ng)/2;
            ll x=calc(i,mid);
            if(x<N)ng=mid;
            else ok=mid;
        }
        chmin(ans,calc(i,ok));
    }

    cout<<ans<<endl;
    return 0;
}
/*
式を見るとa,bの次数は3であるから、Nは10^18であるから、aは高々10^6程度に収まると考えられる。
bを二分探索して条件を満たすXを探索していけばよいと思う。
*/