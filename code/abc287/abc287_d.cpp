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
    string s,t;
    cin>>s>>t;
    int slen=s.size(),tlen=t.size();
    vector<bool> pre(tlen+2,false),suf(tlen+2,false);
    pre[0]=true,suf[0]=true;
    rep(i,tlen){
        if(s[i]!='?'&&t[i]!='?'&&s[i]!=t[i])break;
        pre[i+1]=true;
    }
    reverse(ALL(s));
    reverse(ALL(t));
    rep(i,tlen){
        if(s[i]!='?'&&t[i]!='?'&&s[i]!=t[i])break;
        suf[i+1]=true;
    }
    rep(i,tlen+1){
        if(pre[i]&&suf[tlen-i])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
/*
文字をずらす意味を理解した
suf[i]は右からi番目までは一致しているよっていうのを
pre[i]は左からi番目までは一致していることを示すので、
O(1)で求まるんだね
素直にreverseします
*/