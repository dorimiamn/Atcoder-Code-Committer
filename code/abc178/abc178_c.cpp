//解説AC
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

ll modpow(ll a,ll n,ll mod){
    ll res=1;
    while(n>0){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int main(){
    //2**n
    int n;
    cin>>n;
    if(n<=1){
        cout<<0<<endl;
        return 0;
    }
    ll ans=modpow(10,n,INF)-modpow(9,n,INF)*2+modpow(8,n,INF);
    ans%=INF;
    ans=(ans+INF)%INF;
    cout<<ans<<endl;
    return 0;
}
/*
Ai=0をoAi=9をpとする
pまたはoをベン図で考えると9**n*2-8**n
そのため、Ai=0がないまたはA9=0がないは9**n*2-8**nと表せる。
これを全体から引く
*/

//a=97,z=122