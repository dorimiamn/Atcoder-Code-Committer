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

bool is_Palindrome(string s){
    int n=s.size();
    rep(i,n/2){
        if(s[i]!=s[n-i-1])return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    rep(count,t){
        ll n,k;
        cin>>n>>k;
        string s,t,r,q;
        cin>>s;
        k%=(2*n);
        t=s;
        reverse(ALL(t));
        if(n>k){
            r=t.substr(0,k);
            q=t.substr(n-k);
        }else{
            r=t+t.substr(2*n-k);
            q=t.substr(0,k-n)+t;
        }
        if(r!=q){
            cout<<"No"<<endl;
            continue;
        }
        if(is_Palindrome(r+s)&&is_Palindrome(s+r))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
/*
https://atcoder.jp/contests/arc155/submissions/38467358
参考にさせていただいた解説
S'だけ考えていて回文判定を完全に忘れていました
*/