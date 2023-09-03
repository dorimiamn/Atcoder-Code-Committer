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
    int n;
    cin>>n;
    vi a(n+1,0),b(n+1,0);
    rep(i,n){
        int c,p1=0,p2=0;
        cin>>c>>p1;
        if(c==2){
            p2=p1;
            p1=0;
        }
        a[i+1]=a[i]+p1;
        b[i+1]=b[i]+p2;
    }
    int q;
    cin>>q;
    rep(i,q){
        int l,r;
        cin>>l>>r;
        l--;
        cout<<a[r]-a[l]<<" "<<b[r]-b[l]<<endl;
    }
    /*
    for(auto x:a)cout<<x<<" ";
    cout<<endl;
    for(auto x:b)cout<<x<<" ";
    cout<<endl;
    */
    return 0;
}
/*

*/