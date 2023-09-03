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

using Graph=vii;

int main(){
    int X,Y,A,B,C;
    cin>>X>>Y>>A>>B>>C;
    vector<ll> p(A),q(B),r(C);
    rep(i,A)cin>>p[i];
    rep(i,B)cin>>q[i];
    rep(i,C)cin>>r[i];
    priority_queue<ll> pue;
    sort(ALL(p),greater<ll>());
    sort(ALL(q),greater<ll>());
    rep(i,X)pue.push(p[i]);
    rep(i,Y)pue.push(q[i]);
    rep(i,C)pue.push(r[i]);
    ll sum=0;
    rep(i,X+Y){
        sum+=pue.top();
        //cout<<pue.top()<<" ";
        pue.pop();
    }
    cout<<sum<<endl;
    return 0;
}

//a=97,z=122