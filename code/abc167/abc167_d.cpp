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
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    vector<int> dist(N,0),l(1,0),o;
    rep(i,N){
        ll x;
        cin>>x;
        x--;
        A[i]=x;
    }
    ll p=0,np=-1;
    ll cnt=0;
    while(dist[p]<=1){
        dist[p]++;
        if(dist[p]==2)o.pb(p);
        p=A[p];
        cnt++;
        l.pb(p);
    }
    ll a=0,b=0;
    rep(i,N){
        if(dist[i]==1)a++;
        else if(dist[i]==2){
            b++;
        }
    }
    /*
    for(auto x:o)cout<<x<<" ";
    cout<<endl;
    for(auto x:l)cout<<x<<" ";
    cout<<endl;
    */
    if(a>=K){
        cout<<l[K]+1<<endl;
        //cout<<a<<endl;
        return 0;
    }
    K-=a;
    K%=b;
    cout<<o[K]+1<<endl;
    return 0;
}

//a=97,z=122