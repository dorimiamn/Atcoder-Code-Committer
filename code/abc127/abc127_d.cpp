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

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)


int main(){
    int n,m,cnt=0,s=0;
    cin>>n>>m;
    vi a(n);
    vector<pair<int,int>> bc(m);
    rep(i,n)cin>>a[i];
    rep(i,m){
        int x,y;
        cin>>x>>y;
        bc[i]={y,x};
    }
    sort(ALL(bc),greater<pair<int,int>>());
    vi d;
    for(auto x:bc){
        rep(i,x.second){
            d.pb(x.first);
            cnt++;
            if(cnt>=n)break;
        }
        if(cnt>=n)break;
    }
    sort(ALL(a));
    cnt=0;
    s=d.size();
    ll sum=0;
    rep(i,n){
        if(a[i]<d[cnt]&&cnt<s)a[i]=d[cnt],cnt++;
        sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}

//a=97,z=122