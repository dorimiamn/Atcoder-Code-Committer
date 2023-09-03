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
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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
    int n;
    cin>>n;
    vii sum(1002,vi(1002,0));
    rep(i,n){
        vi x(2),y(2);
        cin>>x[0]>>y[0]>>x[1]>>y[1];
        rep(j,2)x[j]++;
        rep(j,2)y[j]++;
        REP(j,y[0],y[1]){
            sum[j][x[0]]++;
            sum[j][x[1]]--;
        }
    }
    rep(i,1001)rep(j,1001){
        sum[i][j+1]+=sum[i][j];
    }
    vi ans(n+1,0);
    rep(i,1000){
        rep(j,1000){
            // cout<<sum[i+1][j+1];
            ans[sum[i+1][j+1]]++;
        }
        // cout<<endl;
    }
    REP(i,1,n+1)cout<<ans[i]<<endl;
    return 0;
}
/*
尺取法
xだけみる
ooo
ooo

xooo
xooo

imos
*/