/*
勉強させていただいた解説
https://kmjp.hatenablog.jp/entry/2019/10/28/0900
実装で、割っても大丈夫なのか悩んでたのだけど、大丈夫だった。
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
    ll N,K;
    cin>>N>>K;
    vi a(N),f(N);
    rep(i,N){
        cin>>a[i];
    }
    rep(i,N){
        cin>>f[i];
    }

    sort(ALL(a));
    sort(ALL(f),greater<int>());

    ll ok=LongINF,ng=-1;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        ll cnt=K;

        bool check=true;

        rep(i,N){
            ll x=mid/f[i];
            if(x<a[i])cnt-=(a[i]-x);
            if(cnt<0){
                check=false;
                break;
            }
        }
        if(check){
            ok=mid;
        }else{
            ng=mid;
        }
    }

    cout<<ok<<endl;

    return 0;
}
/*
完食にかかる時間は x * y 秒である。
直感的に、x と　y は どちらも sort した後に、片方を逆にしてかけていけば最小にできるとわかるが、
証明をしっかり書けず…。
なんか誤解していたみたい。ちゃんと、手元で試せって何百回も思ってるが身につかないなー
制約！ K は long long じゃないとダメだよ
*/