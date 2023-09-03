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

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int N;
    cin>>N;
    vi A(N);
    rep(i,N)cin>>A[i];

    vi sum(N+1,0);
    REP(i,1,N){
        if(i%2==1)sum[i+1]=sum[i];
        else sum[i+1]=sum[i]+A[i]-A[i-1];
    }
    // for(auto x:sum)cout<<x<<" ";
    // cout<<endl;

    vi ans_arr;

    int Q;
    cin>>Q;
    rep(_,Q){
        int l,r;
        ll ans=0;
        cin>>l>>r;
        int x=lower_bound(ALL(A),l)-A.begin(),y=upper_bound(ALL(A),r)-A.begin()-1;
        if(x%2==0){
            ans+=(A[x]-l);
        }
        if(y%2){
            ans+=(r-A[y]);
        }
        // cout<<x<<" "<<y<<endl;
        // cout<<A[x]<<" "<<l<<endl;
        // cout<<r<<" "<<A[y]<<endl;
        // cout<<ans<<" "<<sum[y+1]<<" "<<sum[x+2]<<endl;
        ans+=sum[y+1]-sum[x+1];
        // cout<<ans<<endl;
        ans_arr.pb(ans);
    }

    for(auto ans:ans_arr)cout<<ans<<endl;

    return 0;
}
//凹みと、角のかけで判定は変えられそう。
/*
二分探索で視点終点の位置を探索する。
累積わで中間の値を出す。
*/