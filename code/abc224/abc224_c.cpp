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
  int n,ans=0;
  cin>>n;
  vector<ll> x(n),y(n);
  rep(i,n)cin>>x[i]>>y[i];
  rep(i,n){
    REP(j,i+1,n){
      REP(k,j+1,n){
        ll area=(x[k]-x[i])*(y[j]-y[i])-(x[j]-x[i])*(y[k]-y[i]);
        if(area!=0)ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
/*
座標所の三角形の面積の求め方習ったっけ……
https://mathwords.net/x1y2hikux2y1
基準は全通り試さなければいけないのでiを使うのか―
*/