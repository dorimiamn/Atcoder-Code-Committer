/*
解説AC
一方を固定して、計算量を落とす問題？
K>=a[i]+b[j]から
b[j]<=K-a[i]を導き、それを用いて、iとjの最大化を図る。
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

int main(){
    ll n,m,k,ans=0;
    cin>>n>>m>>k;
    vector<ll> a(n+1,0),b(m+1,0);
    rep(i,n){
        ll x;
        cin>>x;
        a[i+1]=a[i]+x;
    }
    rep(i,m){
        ll x;
        cin>>x;
        b[i+1]=b[i]+x;
    }
    int j=m;
    rep(i,n+1){
        if(a[i]>k)break;
        while(b[j]>k-a[i]){
            j--;
        }
        ans=max(ans,i+j);
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122