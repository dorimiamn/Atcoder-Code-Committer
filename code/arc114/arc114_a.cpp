#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=4611686018427388000;
const int INF=1073741824;
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

vi prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main(){
    int N;
    cin>>N;
    vi A(N);
    rep(i,N)cin>>A[i];
    ll ans=LongINF;
    for(ll bit=0;bit<(1<<15);bit++){
        ll a=1;
        rep(i,15){
            if(bit&(1<<i)){
                a*=prime[i];
            }
        }
        bool ok=true;
        rep(i,N){
            if(GCD(a,A[i])==1){
                ok=false;
                break;
            }
        }
        if(ok){
            chmin(ans,a);
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/