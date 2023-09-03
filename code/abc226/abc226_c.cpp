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
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

void dfs(vector<bool> &dist,vii &graph,int x){
    if(x==0){
        return ;
    }
    for(auto y:graph[x]){
        if(dist[y])continue;
        dist[y]=true;
        dfs(dist,graph,y);
    }
}

int main(){
    int N;
    cin>>N;
    vi t(N),k(N);
    vii graph(N);
    rep(i,N){
        cin>>t[i]>>k[i];
        rep(j,k[i]){
            int x;
            cin>>x;
            x--;
            graph[i].pb(x);
        }
    }

    vector<bool> dist(N);
    dist[N-1]=true;

    dfs(dist,graph,N-1);

    ll sum=0;

    rep(i,N){
        if(dist[i]){
            sum+=t[i];
        }
    }

    cout<<sum<<endl;

    return 0;
}
/*
技Nからさかのぼる
*/