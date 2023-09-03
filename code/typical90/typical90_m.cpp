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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int n,m;
vii graph(100000);
map<pair<int,int>,int> cost;
int res[2][100000];

void bfs(int start ,int num){
    vector<bool>dist(n,false);
    dist[start]=true;
    queue<int>que;
    que.push(start);
    while(!que.empty()){
        int x=que.front();
        que.pop();
        for(auto y:graph[x]){
            if(res[num][y]>res[num][x]+cost[{x,y}]){
                res[num][y]=res[num][x]+cost[{x,y}];
                que.push(y);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        graph[a].pb(b);
        graph[b].pb(a);
        cost[{a,b}]=c;
        cost[{b,a}]=c;
    }
    rep(i,2)rep(j,n)res[i][j]=INF;
    res[0][0]=0,res[1][n-1]=0;
    bfs(0,0);
    bfs(n-1,1);
    rep(i,n){
        cout<<res[0][i]+res[1][i]<<endl;
    }
    return 0;
}
/*

*/