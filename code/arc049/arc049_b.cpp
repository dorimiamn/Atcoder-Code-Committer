//解説Submit
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

int main(){
    int N;
    cin>>N;

    vector a(N,array<double,3>{});

    rep(i,N){
        rep(j,3){
            cin>>a[i][j];
        }
    }

    auto check=[&](double t) -> bool {
        vector<double> x(2),y(2);
        x[0]=y[0]=-1e18;
        x[1]=y[1]=1e18;
        rep(i,N){
            //x軸
            chmax(x[0],a[i][0]-t/a[i][2]);
            chmin(x[1],a[i][0]+t/a[i][2]);
            //y軸
            chmax(y[0],a[i][1]-t/a[i][2]);
            chmin(y[1],a[i][1]+t/a[i][2]);
        }
        if(x[0]<=x[1]&&y[0]<=y[1])return true;
        return false;
    };

    double ok=1e18,ng=0.0;
    rep(i,100){
        double md=(ok+ng)/2;
        if(check(md))ok=md;
        else ng=md;
    }

    cout<<decimal(10)<<ok<<endl;

    return 0;
}
/*
方針としては、あるYに対して、最適なXを見つける感じでやりたい。
座標を二分探索する。
Yについて二分探索し、それに対して最適なXを二分探索。
線形性があるのかどうかわからん。いやー、あるんじゃないか？
線形ではなく、放物線の可能性もあるか？

解説読んだ

ノルムくんのいる座標から、移動するのに等しい時間がかかる場所を線で考える。
この線によってできた図形が全てのノルムくんの座標からできる図形と共通な部分をもてば
それが答えとなる。

二分探索で意識するべきなのは、どのようにして単調性のある判定関数を作るかってことかな
二分探索も、判定関数と切り分けて書くべきなんだけど、全然慣れてなくて良くないので慣れよう

tについて二分探索して、判定してく感じ

C++のラムダ式を使えば関数の中で関数を宣言できるのかな？
*/