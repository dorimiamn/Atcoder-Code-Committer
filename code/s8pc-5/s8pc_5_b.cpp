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
    int n,m;
    double right=1e5,left=0.000000000;
    cin>>n>>m;
    vector<double> x(n+m),y(n+m),r(n);
    rep(i,n){
        cin>>x[i]>>y[i]>>r[i];
        right=min(right,r[i]);
    }
    rep(i,m)cin>>x[n+i]>>y[n+i];
    rep(k,100){
        double middle=(right+left)/2;
        //cout<<decimal(7)<<left<<" "<<right<<" "<<middle<<endl;
        bool ok=true;
        rep(i,n+m){
            REP(j,i+1,m+n){
                double r1=(i<n?r[i]:middle),r2=(j<n?r[j]:middle);
                double D=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                if(D<r1+r2)ok=false;
            }
        }
        if(ok)left=middle;
        else right=middle;
    }
    cout<<decimal(10)<<left<<endl;
    return 0;
}
/*
最小半径を二分探索で求めていくんじゃないかな。
NlogNぐらいの計算量を見込んでいるよ
不動小数点の計算なので、回数で求められたかを考える？
r[i]とすべきところをx[i]としていた...

https://drken1215.hatenablog.com/entry/2021/08/08/165000
実装で詰まったのでけんちょん様の実装と比較させていただいた。
*/