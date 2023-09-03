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

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int A,B,Q;
    cin>>A>>B>>Q;
    vi s(A),t(B);
    rep(i,A)cin>>s[i];
    rep(i,B)cin>>t[i];

    rep(_,Q){
        //x に近い神社二つからお寺をまた求める
        ll x,ans=LongINF;
        cin>>x;
        rep(i,2){
            int index1=upper_bound(ALL(s),x)-s.begin()-1+i;
            if(index1<0||index1==A)continue;;
            rep(j,2){
                int index2=upper_bound(ALL(t),s[index1])-t.begin()-1+j;
                if(index2<0||index2==B)continue;
                // cout<<"index:"<<index1<<" "<<index2<<endl;
                // cout<<"arr:"<<s[index1]<<" "<<s[index2]<<endl;
                // cout<<"ans:"<<abs(x-s[index1])+abs(s[index1]-t[index2])<<endl;
                chmin(ans,abs(x-s[index1])+abs(s[index1]-t[index2]));
            }
        }
        //お寺から神社
        rep(i,2){
            int index1=upper_bound(ALL(t),x)-t.begin()-1+i;
            if(index1<0||index1==B)continue;;
            rep(j,2){
                int index2=upper_bound(ALL(s),t[index1])-s.begin()-1+j;
                if(index2<0||index2==A)continue;
                // cout<<"index:"<<index1<<" "<<index2<<endl;
                // cout<<"arr:"<<s[index1]<<" "<<s[index2]<<endl;
                // cout<<"ans:"<<abs(x-s[index1])+abs(s[index1]-t[index2])<<endl;
                chmin(ans,abs(x-t[index1])+abs(t[index1]-s[index2]));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
右向きの数直線を考える。
二分探索で現在地から最も近い右側の神社と寺を求める
その後インデックスを減らして左側の最も近い神社と寺を求める
神社と寺の組み合わせから答えは求まるはず
*/