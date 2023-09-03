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
    int N,Q;
    cin>>N;
    vii idx(N+1);
    rep(i,N){
        int a;
        cin>>a;
        idx[a].pb(i);
    }

    cin>>Q;

    rep(q,Q){
        int l,r,x;
        cin>>l>>r>>x;
        // cout<<lower_bound(ALL(idx[x]),r)-idx[x].begin()<<" "<<lower_bound(ALL(idx[x]),l-1)-idx[x].begin()<<endl;
        cout<<lower_bound(ALL(idx[x]),r)-lower_bound(ALL(idx[x]),l-1)<<endl;
    }
    return 0;
}
/*
文字ごとに、indexを持ってそれを用いて二分全探索すれば良い。
考えるべきなのは1文字だけであり、他の文字は関係ない。

求めるべきindexがR+1なのは、「R以下」なので、それを満たさないものを探す必要があるから。Rをindexで求めると弾きすぎてしまう。

lowerとupperを使う？
*/