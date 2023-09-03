/*
https://twitter.com/8pGCJmg4nVU2o37/status/1680212677342433280?s=20
勉強させていただいた解説
*/

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
    string S;
    cin>>N>>S;
    ll cnt=0;
    ll ans=0;
    rep(i,N){
        if(S[i]=='0'){
            ans+=i;
            cnt=0;
        }
        if(S[i]=='1'){
            cnt++;
            if(cnt%2){
                //奇数個ある場合、直前の0から始めた場合のみ1となり、それ以外は0。よって連続する1より前で1となるのは1つ
                //連続する1の中で否定論理積が1となるのは(cnt+1)/2個
                ans+=(cnt+1)/2;
                //直前に0があるなら加算
                if(i-cnt+1)ans++;
            }else{
                //連続する1以前の文字数-1+連続する1の数/2が答え
                ans+=(cnt)/2;
                if(i-cnt+1)ans+=i-cnt;
            }
        }
        // cout<<i<<": "<<cnt<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
4
1111
の際に挙動が違った
*/