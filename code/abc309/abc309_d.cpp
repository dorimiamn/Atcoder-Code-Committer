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

int main(){
    int N1,N2,M;
    cin>>N1>>N2>>M;
    vii graph(N1+N2);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vi dist(N1+N2,INF);

    dist[0]=dist[N1+N2-1]=0;

    priority_queue<pair<int,int>>que;
    que.push({0,0});
    que.push({N1+N2-1,0});
    while(!que.empty()){
        auto [vertex,cost]=que.top();
        que.pop();

        if(cost >dist[vertex])continue;

        for(auto nvertex:graph[vertex]){
            if(dist[nvertex]<=cost+1)continue;
            dist[nvertex]=cost+1;
            que.push({nvertex,cost+1});
        }
    }

    int d1=0,i1=0;
    int d2=0,i2=N1+N2-1;
    rep(i,N1){
        if(d1<dist[i]){
            d1=dist[i];
            i1=i;
        }
    }
    REP(i,N1,N1+N2){
        if(d2<dist[i]){
            d2=dist[i];
            i2=i;
        }
    }

    graph[i1].pb(i2);
    graph[i2].pb(i1);

    rep(i,N1+N2)dist[i]=INF;

    que.push({0,0});
    while(!que.empty()){
        auto [vertex,cost]=que.top();
        que.pop();

        if(cost >dist[vertex])continue;

        for(auto nvertex:graph[vertex]){
            if(dist[nvertex]<=cost+1)continue;
            dist[nvertex]=cost+1;
            que.push({nvertex,cost+1});
        }
    }

    cout<<dist[N1+N2-1]<<endl;

    return 0;
}
/*
dijkstra で最も遠い頂点を探索
その遠いどおしを線でつないだら答えになるのでは？
*/