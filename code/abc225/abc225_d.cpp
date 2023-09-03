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
  int n,q;
  cin>>n>>q;
  vector<ll> front(n+1,-1),back(n+1,-1);
  rep(i,q){
    int x,y,z;
    cin>>z;
    if(z==1){
      cin>>x>>y;
      front[y]=x,back[x]=y;
    }else if(z==2){
      cin>>x>>y;
      front[y]=-1,back[x]=-1;
    }else{
      cin>>x;
      while (front[x]!=-1){
        x=front[x];
      }
      vector<ll>ans;
      while(x!=-1){
        ans.pb(x);
        x=back[x];
      }
      cout<<ans.size()<<endl;
      rep(j,ans.size()){
        cout<<ans[j];
        if(j!=ans.size()-1)cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
/*
解説AC
解説見たらすごいシンプルで感動した

*/