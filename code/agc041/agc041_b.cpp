/*
勉強させていただいた解説
https://at274.hatenablog.com/entry/2020/06/18/235902
https://scrapbox.io/procon-kirokuyou/AGC041_B_-_Voting_Judges_(700)
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

ll N,M,V,P;

bool solve(ll &t,vi a){
    a[t]+=M;
    ll rem=M*(V-1);
    rep(i,P-1){
        a[N-i-1]+=M;
        rem-=M;
    }

    REP(i,0,t){
        rem-=M;
        a[i]+=M;
    }

    REP(i,t+1,N-P+1){
        if(rem<=0){
            while(i<N&&a[i]<=a[t])i++;
            return N-i+1<=P;
        }
        ll diff=max(0LL,min(rem,a[t]-a[i]));
        rem-=diff;
        a[i]+=diff;
    }
    return rem<=0;
}

ll binary_search(vi &a){
    //参照渡しの有効活用
    ll ok=N,ng=-1;

    while(abs(ok-ng)>1){
        ll md=(ok+ng)/2;
        if(solve(md,a))ok=md;
        else ng=md;
    }

    return ok;
}

int main(){
    cin>>N>>M>>V>>P;
    vi a(N);
    rep(i,N){
        cin>>a[i];
    }
    sort(ALL(a));
    

    cout<<N-binary_search(a)<<endl;

    return 0;
}
/*
V 問に投票できるとあって、この部分は余票の処理に相当する。
これが処理できるかどうかで、可能性があるか決まる
考えるべきなのは、M 票集まった時、 P問のうちに入れるかどうか。
ng と ok の差を絶対値とって減らしていく感じなのか
*/