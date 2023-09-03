#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e17+7;
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
    int n,a,b;
    ll ans=0;
    string s;
    cin>>n>>a>>b>>s;
    deque<char>que;
    rep(i,n)que.push_back(s[i]);
    rep(i,n/2){
        if(que[i]!=que[n-i-1])ans+=b;
    }
    rep(i,n){
        ll sum=a*(i+1);
        que.push_back(que.front());
        que.pop_front();
        rep(j,n/2){
            if(que[j]!=que[n-j-1])sum+=b;
        }
        chmin(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
/*
文字列まるごとシフト
シフトするごとに文字を回文にするコストをだす
*/