/*
勉強させていただいたSubmit
https://atcoder.jp/contests/abc192/submissions/20280841
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

//LongINFが1e18だと思ったら1e14になってた
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

bool check(ll n,string str,ll M){
    // cout<<"n:"<<n<<endl;
    ll x=0;
    for(char c:str){
        c-='0';
        // M/n を判定に用いるのは、オーバーフロー対策
        // n*x>M の代わり
        if(x>M/n){
            return 0;
        }
        x*=n;
        x+=c;
        // cout<<x<<endl;
    }
    return x<=M;
}

int main(){
    string X;
    ll M;
    cin>>X>>M;

    if(X.size()==1){
        cout<<check(10,X,M)<<endl;
        return 0;
    }

    //配列に対して max_element関数を使うことで最大の要素のイテレータを取り出せるんだすごい
    ll d=*max_element(ALL(X))-'0';
    //1e18も回答に入る感じ？
    ll ok=d,ng=LongINF+1;
    
    while(ng-ok>1){
        ll mid=(ok+ng)/2;
        // cout<<"mid:"<<mid<<"ok:"<<ok<<"ng:"<<ng<<endl;

        if(check(mid,X,M))ok=mid;
        else ng=mid;
    }

    cout<<ok-d<<endl;

    return 0;
}
/*
多分n進法について二分探索を行なって,Mの条件を満たせるnを探せば良さそう。

https://blog.hamayanhamayan.com/entry/2021/02/20/233715
私は10進法に変換するやり方しか考えていなかったが、逆にn進法にMを変換して比べるっていう方法もあってなるほどなって思った。
*/