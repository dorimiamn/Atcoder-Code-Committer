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
    ll N,M,D;
    cin>>N>>M>>D;
    vector<ll> A(N),B(N);
    rep(i,N)cin>>A[i];
    rep(i,M)cin>>B[i];
    sort(ALL(A));
    sort(ALL(B));

    ll ans=-1;

    rep(i,N){
        int p1=lower_bound(ALL(B),A[i]-D)-B.begin(),p2=upper_bound(ALL(B),A[i]+D)-B.begin();
        if(abs(B[p1]-A[i])<=D)ans=max(ans,A[i]+B[p1]);
        if(abs(B[p2-1]-A[i])<=D)ans=max(ans,B[p2-1]+A[i]);
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/