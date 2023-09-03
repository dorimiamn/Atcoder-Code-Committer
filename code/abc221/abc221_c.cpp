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

ll convertInt(string x){
  ll a=0;
  for(auto y:x){
    a=a*10+(y-'0');
  }
  return a;
}

int main(){
  string s;
  cin>>s;
  ll len=s.length(),ans=0;
  if(len==1){
    ans=convertInt(s);
  }else{
    for(int bit=0;bit<(1<<len);++bit){
      string t,r;
      rep(i,len){
        if(bit&(1<<i))t.pb(s[i]);
        else r.pb(s[i]);
      }
      do{
        do{
          if(t[0]=='0'||r[0]=='0')continue;
          ll a=convertInt(t),b=convertInt(r);
          chmax(ans,a*b);
        }while(next_permutation(ALL(t)));
      }while(next_permutation(ALL(r)));
    }
  }
  cout<<ans<<endl;
  return 0;
}
/*
文字列を用いて二つの数に分離する。
*/