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

int LimitCheck(int x){
  return max(min(10000,x),0);
}
void putNum(int num){
  cout<<num<<endl;
}

int main(){
  int n;
  cin>>n;
  vector<tuple<int,int,int>> sponsor(n);
  vector<tuple<int,int,int,int>> ans(n);
  vector<tuple<int,int,int>> left;
  vector<pll> points;
  rep(i,n){
    int x,y,r;
    cin>>x>>y>>r;
    sponsor[i]={r,x,y};
  }
  for(auto& [r,x,y]:sponsor){
    cout<<x<<" "<<y<<" "<<x+1<<" "<<y+1<<endl;
  }
  return 0;
}
/*
対角の頂点がc,d
5407 422 6115 1130
5261 577 5753 1069

overlap 3&33
5767 3140 6179 3552
5671 3305 6288 3922

overlap 23&&36
8544 8196 9204 8856
8575 8200 9100 8947

2
8544 8196 1742491
8575 8200 3662259


*/