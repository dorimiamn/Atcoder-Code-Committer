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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int n,cnt=0;
    cin>>n;
    vector<int> q(200002,0);
    vi ans;
    rep(i,n){
        int l,r;
        cin>>l>>r;
        l--,r--;
        q[l]++;
        q[r]--;
    }
    REP(i,1,200002){
        q[i]+=q[i-1];
    }
    bool ok=false;
    if(q[0]){
        ans.pb(0);
        ok=true;
    }
    REP(i,1,200002){
        if(q[i]){
            if(!ok){
                ans.pb(i);
            }
            ok=true;
        }else{
            if(ok){
                ans.pb(i);
            }
            ok=false;
        }
    }
    // for(auto x:ans)cout<<x<<endl;
    rep(i,ans.size()/2){
        cout<<ans[2*i]+1<<" "<<ans[2*i+1]+1<<endl;
    }
    return 0;
}
/*

*/