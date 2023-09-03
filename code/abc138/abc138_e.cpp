//解説Submit
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
    string S,T;
    cin>>S>>T;
    S+=S;
    vii ch(27);
    rep(i,S.length()){
        ch[S[i]-'a'].pb(i+1);
    }
    ll pos=1,ans=0;
    rep(i,T.length()){
        auto itr=lower_bound(ALL(ch[T[i]-'a']),pos);
        if(itr==ch[T[i]-'a'].end()){
            ans=-1;
            break;
        }
        ll index=*itr;
        ans+=index-pos+1;
        pos=index%(S.length()/2)+1;
        // cout<<ans<<" "<<pos<<" "<<index<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
Tに着目すれば、O(|T|)だよね
Tの文字がS'にあるかどうかなので、愚直にやるならば、Tの各文字に対してSの各文字を照らしてみていくわけで、
これをO(1)で出来たらO(|T|)でやれるよねって。
だから、各文字に対してインデックスを取って、二分探索を用いて次の文字のインデックスを求めていくことで制限時間内に答えることが可能
*/