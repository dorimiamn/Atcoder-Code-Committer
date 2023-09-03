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
    int h,w;
    cin>>h>>w;
    vii a(h,vi(w));
    rep(i,h)rep(j,w)cin>>a[i][j];
    vi vertical(h,0),horizontal(w,0);
    rep(i,h){
        int cnt=0;
        rep(j,w){
            cnt+=a[i][j];
        }
        vertical[i]=cnt;
    }
    rep(i,w){
        int cnt=0;
        rep(j,h){
            cnt+=a[j][i];
        }
        horizontal[i]=cnt;
    }
    rep(i,h){
        rep(j,w){
            cout<<vertical[i]+horizontal[j]-a[i][j];
            if(j==w-1)cout<<endl;
            else cout<<" ";
        }
    }
    return 0;
}
/*

*/