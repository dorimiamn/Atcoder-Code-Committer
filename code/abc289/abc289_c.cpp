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
    int n,m,cnt=0;
    cin>>n>>m;
    vii a(m,vi(n));
    rep(i,m){
        int c;
        cin>>c;
        rep(j,c)cin>>a[i][j];
    }
    vector<set<int>> sets;
    for(int bit=0;bit<(1<<m);bit++){
        set<int>s;
        rep(j,m){
            if(bit&(1<<j)){
                for(auto x:a[j]){
                    if(x==0)break;
                    s.insert(x);
                }
            }
        }
        sets.push_back(s);
        // for(auto x:s)cout<<x<<" ";
        // cout<<endl;
    }
    for(auto s:sets){
        if(s.size()==n)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
/*

*/