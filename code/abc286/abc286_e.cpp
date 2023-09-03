#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef tuple<ll,ll,ll>tll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
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
    int n,q;
    cin>>n;
    vi a(n);
    vii graph(n);
    vector<string> s(n);
    rep(i,n){
        cin>>a[i];
        a[i]*=-1;
    }
    rep(i,n){
        cin>>s[i];
        rep(j,n){
            if(s[i][j]=='Y'){
                graph[i].pb(j);
            }
        }
    }
    vector<vector<pll>> dist_mater(n);
    rep(i,n){
        priority_queue<tll,vector<tll>,greater<tll>>que;//おみやげの価値を負で考えることでgreaterの基準を統一できる
        vector<pll>dist(n,{INF,INF});
        dist[i]={0,a[i]};
        que.push({0,a[i],i});
        while(!que.empty()){
            auto [cost,worth,from]=que.top();
            que.pop();
            for(auto to:graph[from]){
                if(dist[to].first>=dist[from].first+1){
                    dist[to].first=dist[from].first+1;
                    chmin(dist[to].second,dist[from].second+a[to]);
                    que.push({dist[to].first,dist[to].second,to});
                }
            }
        }
        dist_mater[i]=dist;
    }
    cin>>q;
    rep(i,q){
        int u,v,ans=0;
        cin>>u>>v;
        u--,v--;
        if(dist_mater[u][v].first==INF)cout<<"Impossible"<<endl;
        else cout<<dist_mater[u][v].first<<" "<<-dist_mater[u][v].second<<endl;
    }
    return 0;
}
/*
BFSで最短本数をとる
そのときのおみやげを比較？
queueは位置とそこまでのおみやげ?
回数も持たせたい
N始点スタート?
参考にさせていただいた提出
*/