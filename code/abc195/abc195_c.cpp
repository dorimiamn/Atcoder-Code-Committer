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
  string s;
  ll n=0,ans=0;
  cin>>s;
  int l=s.size();
  rep(i,l){
    int a=int(s[i]-'0');
    n=n*10+a;
  }
  ll cnt=0,comma=0;
  rep(i,l){
    cnt++;
    if(cnt==4){
      comma++;
      cnt=1;
    }
    if(i!=l-1){
      ll a=i,up=9,down=1;
      while(a!=0){
        a--;
        up=up*10+9;
        down=down*10;
      }
      ans+=comma*(up-down+1);
      //cerr<<up<<" "<<down<<" "<<comma<<endl;
    }else{
      ll a=i,up=n,down=1;
      while(a>0){
        a--;
        down=down*10;
      }
      ans+=comma*(up-down+1);
      //cerr<<up<<" "<<down<<" "<<comma<<endl;
    }
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
/*
99999と10000の差し引きからcommaを求める
*/