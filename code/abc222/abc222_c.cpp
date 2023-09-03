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

int isWin(char a,char b){
  char G='G',C='C',P='P';
  int ans=0;
  //a win =0,equal=1,a lose =2;
  if(a==G){
    if(b==G)ans=1;
    else if(b==P)ans=2;
  }else if(a==C){
    if(b==C)ans=1;
    else if(b==G)ans=2;
  }else{
    if(b==P)ans=1;
    else if(b==C)ans=2;
  }
  return ans;
}

int main(){
  int n,m;
  cin>>n>>m;
  n*=2;
  vector<string> s(n);
  rep(i,n)cin>>s[i];
  vector<pair<int,int>> win(n);
  rep(i,n)win[i].first=0,win[i].second=i;
  rep(i,m){
    rep(j,n/2){
      int a=win[2*j].second,b=win[2*j+1].second,ans=isWin(s[a][i],s[b][i]);
      // cout<<a<<" "<<b<<endl;
      if(ans==0)win[2*j].first--;
      else if(ans==2)win[2*j+1].first--;
    }
    sort(ALL(win));
    // for(auto x:win)cout<<"win:"<<x.second<<" "<<x.first<<endl;
  }
  rep(i,n)cout<<win[i].second+1<<endl;
  return 0;
}
/*

*/