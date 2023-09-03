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
    vector<string> s(h);
    vii l(h,vi(w,0)),r(h,vi(w,0)),u(h,vi(w,0)),d(h,vi(w,0));
    rep(i,h)cin>>s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#')continue;
            if(j==0)l[i][j]=1;
            else l[i][j]=l[i][j-1]+1;
            if(i==0)u[i][j]=1;
            else u[i][j]=u[i-1][j]+1;
        }
    }
    for(int i=h-1;i>=0;i--){
        for(int j=w-1;j>=0;j--){
            if(s[i][j]=='#')continue;
            if(j==w-1)r[i][j]=1;
            else r[i][j]=r[i][j+1]+1;
            if(i==h-1)d[i][j]=1;
            else d[i][j]=d[i+1][j]+1;
        }
    }
    int ans=0;
    rep(i,h){
        rep(j,w){
            ans=max(ans,l[i][j]+r[i][j]+u[i][j]+d[i][j]-3);
        }
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122