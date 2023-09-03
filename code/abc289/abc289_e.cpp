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
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

struct member{
    int takahashi;
    int aoki;
    int cnt;
};

int main(){
    int t;
    cin>>t;
    vi ans;
    rep(test,t){
        int n,m;
        cin>>n>>m;
        vi c(n,0);
        vii graph(n,vi(0));
        vector<vector<bool>> dist(n,vector<bool>(n,false));
        rep(i,n)cin>>c[i];
        rep(i,m){
            int u,v;
            cin>>u>>v;
            u--,v--;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        bool answered=false;
        queue<member>que;
        que.push({0,n-1,0});
        dist[0][n-1]=true;
        while(!que.empty()){
            int takahashi=que.front().takahashi,aoki=que.front().aoki,count=que.front().cnt;
            que.pop();
            for(auto x:graph[takahashi]){
                for(auto y:graph[aoki]){
                    if(dist[x][y])continue;
                    if(c[x]==c[y])continue;
                    if(x==n-1&&y==0){
                        ans.pb(count+1);
                        dist[x][y]=true;
                        break;
                    }
                    dist[x][y]=true;
                    que.push({x,y,count+1});
                }
                if(dist[n-1][0])break;
            }
        }
        if(!dist[n-1][0])ans.pb(-1);
    }
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    return 0;
}
/*

*/