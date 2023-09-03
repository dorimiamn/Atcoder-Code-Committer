#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
const int INF=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    ll N,A,B;
    cin>>N>>A>>B;
    vi h(N);
    rep(i,N)cin>>h[i];

    A-=B;

    ll ok=INF,ng=-1;

    auto check=[&](ll x) -> bool {
        vi hc=h;
        ll cnt=0;
        rep(i,N){
            if(hc[i]-x*B>0){
                cnt+=(hc[i]-x*B+A-1)/A;
            }
        }
        if(cnt>x)return false;
        return true;
    };

    while(ok-ng>1){
        ll md=(ok+ng)/2;

        if(check(md))ok=md;
        else ng=md;
    }

    cout<<ok<<endl;

    return 0;
}
/*
爆発の回数を二分探索するが、このときどのように考えるかというと
すべての魔物にB*Tのダメージを与えたうえで、残った魔物をT回Aのダメージを与えることで倒せるかどうか
誤読していて、ダメージが通る範囲に制限があると考えてしまった。
問題文をちゃんと読もう！
困ったらlong long
*/