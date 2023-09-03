//解説AC
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
  int n,m,ans=INF;
  cin>>n>>m;
  vi h(n),w(m),sum1((n+1)/2,0),sum2((n+1)/2,0);
  rep(i,n)cin>>h[i];
  rep(i,m)cin>>w[i];
  sort(ALL(h));
  for(int i=0;i+1<n;i+=2)sum1[i/2+1]=sum1[i/2]+h[i+1]-h[i];
  for(int i=n-2;i>0;i-=2)sum2[i/2]=sum2[i/2+1]+h[i+1]-h[i];
  for(auto x:w){
    int y=lower_bound(ALL(h),x)-h.begin();
    if(y&1) y^=1;
    chmin(ans,sum1[y/2]+sum2[y/2]+abs(h[y]-x));
  }
  cout<<ans<<endl;
  return 0;
}
/*
累積和を使うことで、計算を高速化できる。
考え方としては左右から累積和を求めて置き、H[i]の計算時に、H[i]を除いた左右からの累積和にabs(H[i]-最適なw)が解となる
ペア単位で考えるので2ずつ更新

*/