#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

ll n,m,s,t;

vi dijkstra(vector<vector<pair<ll,ll>>> &fares ,ll &p){
    vi dist(n,LongINF);
    dist[p]=0;
    priority_queue<pll,vector<pll>,greater<pll>>que;
    que.push({0,p});
    while(!que.empty()){
        auto [sum,v]=que.top();
        que.pop();
        for(auto [nv,cost]:fares[v]){
            if(sum+cost<dist[nv]){
                dist[nv]=sum+cost;
                que.push({dist[nv],nv});
            }
        }
    }
    return dist;
}

int main(){
    cin>>n>>m>>s>>t;
    vector<vector<pair<ll,ll>>> yen(n),snuke(n);
    s--,t--;
    rep(i,m){
        ll u,v,a,b;
        cin>>u>>v>>a>>b;
        u--,v--;
        yen[u].pb({v,a});
        yen[v].pb({u,a});
        snuke[u].pb({v,b});
        snuke[v].pb({u,b});
    }
    vi dist1=dijkstra(yen,s),dist2=dijkstra(snuke,t),ans(n,LongINF);
    ans[n-1]=dist1[n-1]+dist2[n-1];
    REP(i,1,n){
        ans[n-i-1]=min(ans[n-i],dist1[n-i-1]+dist2[n-i-1]);
    }
    for(auto fare:ans){
        cout<<LongINF-fare<<endl;
    }
    return 0;
}
/*
両替一回だけ！
s,tから両替所までの経路の最小を求めればよい
*/