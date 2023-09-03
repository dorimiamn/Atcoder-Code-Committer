//解説submit
//添字の扱いを色々とミスった……
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T,class Y> inline bool chmin(T& a, Y b) {if (a > b) {a = b;return true;}return false;}
template<class T,class Y> inline bool chmax(T& a, Y b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    ll n,c;
    ll sum=0,m=0,ans=0;
    cin>>n>>c;
    vi x(n+2,0),v(n+2,0),a(n+1,0),b(n+1,0);
    x[n+1]=c;
    rep(i,n)cin>>x[i+1]>>v[i+1];
    REP(i,1,n+1){
        sum+=v[i];
        a[i]=max(sum-x[i],m);
        chmax(m,a[i]);
    }
    sum=0;
    m=0;
    //最大値を都度求めているので、距離によるカロリー消費が狂っている
    for(int i=n;i>=1;i--){
        sum+=v[i];
        b[n-i+1]=max(sum-abs(c-x[i]),m);
        //cout<<m<<":"<<x[i+1]-x[i]<<endl;
        chmax(m,b[n-i+1]);
    }
    /*
    for(auto x:a)cout<<x<<" ";
    cout<<endl;
    for(auto x:b)cout<<x<<" ";
    cout<<endl;
    */
    sum=0;
    rep(i,n+1){
        sum+=v[i];
        chmax(ans,sum+b[n-i]-2*x[i]);
        //cout<<ans<<"::"<<sum<<":"<<b[n-i]<<endl;
    }
    sum=0;
    for(int i=n+1;i>=1;i--){
        sum+=v[i];
        chmax(ans,sum+a[i-1]-2*(c-x[i]));
        //cout<<ans<<":"<<sum<<":"<<a[i-1]<<endl;
    }
    chmax(ans,a[n]);
    chmax(ans,b[n]);
    cout<<ans<<endl;
    return 0;
}
/*

*/