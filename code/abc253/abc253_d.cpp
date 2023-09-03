#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
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
    ll n,a,b,c;
    cin>>n>>a>>b;
    c=lcm(a,b);
    ll x=n/a,y=n/b,z=n/c;
    ll sum0=n*(n+1)/2,sum1=a*x*(x+1)/2,sum2=b*y*(y+1)/2,sum3=c*z*(z+1)/2;
    // cout<<sum0<<" "<<sum1<<" "<<sum2<<" "<<sum3<<endl;
    cout<<sum0-sum1-sum2+sum3<<endl;
    return 0;
}
/*
解説四で理解した。
重複して引いているところがあるね！！！
包助原理
*/