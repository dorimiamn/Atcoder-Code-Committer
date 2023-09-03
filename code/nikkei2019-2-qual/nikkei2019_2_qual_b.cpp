/*
https://yamakasa.net/dainikai-zenkoku-touitu-procon-b/
勉強させて頂いた解説

整数列dの最大値を用いてloopさせたが、一部0を出力するケースで落ちるのでnで試す。
0以外でもダメなとこあるやん。
最初に0がこないとダメだよね！
整数列Dはi番目の頂点との距離を表しているため、0番目は当然距離0でなければならない。
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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int MOD = 998244353;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main(){
    ll n,ans=1;
    cin>>n;
    vector<ll>mp(n,0),d(n);
    rep(i,n){
        cin>>d[i];
        mp[d[i]]++;
    }
    //0が二つあったらおかしい
    if(mp[0]!=1||d[0]!=0){
        cout<<0<<endl;
        return 0;
    }
    bool ok=true;
    rep(i,n){
        if(mp[i]==0){
            ok=false;
        }else{
            if(!ok){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    rep(i,n-1){
        //cout<<mp[i]<<"->"<<mp[i+1]<<endl;
        //上の頂点の数だけ選択肢があるため、それに下の頂点の数をかけることで木の数がわかる？
        //2のn乗の2の部分が上の頂点になっただけ。
        ans*=modpow(mp[i],mp[i+1]);
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122