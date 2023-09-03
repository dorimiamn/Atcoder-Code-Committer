#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=9223372036854775807;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
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
    ll x,a,d,n;
    cin>>x>>a>>d>>n;
    if(d<0){
        ll fi=a+d*(n-1);
        a=fi;
        d*=-1;
    }
    ll ok=n-1,ng=0;
    while(ok-ng>100){
        ll mid=(ok+ng)/2;
        if(x>(mid*d+a))ng=mid+1;
        else ok=mid-1;
       // cout<<mid*d<<" "<<ok<<" "<<ng<<endl;
    }
    ll ans=LongINF;
    REP(i,max(0LL,ng-5),min(n,ok+10)){
        chmin(ans,abs(a+d*i-x));
    }
    cout<<ans<<endl;
    return 0;
}
/*
Xが数列内部にあるかどうか
内部の時は位置を絞る
項数で二分探索
*/