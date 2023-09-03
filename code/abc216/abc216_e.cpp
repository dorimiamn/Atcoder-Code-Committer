#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
const int INF=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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
    ll N,K;
    cin>>N>>K;
    vi a(N);
    rep(i,N)cin>>a[i];
    sort(ALL(a),greater<ll>());

    ll ok=LongINF,ng=0;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        ll sum=0;
        rep(i,N){
            if(a[i]<mid)break;
            sum+=(a[i]-mid+1);
        }
        if(sum<=K)ok=mid;
        else ng=mid;
    }

    ll ans=0,sum=0;

    rep(i,N){
        if(a[i]<ok)break;
        ll cnt=a[i]-ok+1;
        ans+=(ok+a[i])*cnt/2;
        sum+=cnt;
    }

    ans+=(K-sum)*ng;

    cout<<ans<<endl;

    // cout<<ok<<" "<<ng<<" "<<sum<<endl;

    return 0;
}
/*
楽しさ基準で二分探索
okはK回を超えない
ngはK回を超える
方針はあってそう？
*/