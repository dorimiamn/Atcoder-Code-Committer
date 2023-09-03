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

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

struct state{
    int y,x,dir;
};

int main(){
    int h,w;
    cin>>h>>w;
    vi s(2),t(2);
    rep(i,2){
        cin>>s[i];
        s[i]--;
    }
    rep(i,2){
        cin>>t[i];
        t[i]--;
    }
    vector<string> graph(h);
    rep(i,h)cin>>graph[i];
    vector<vector<vector<int>>> dist(h,vii(w,vi(4,INF)));
    deque<state> que;
    rep(i,4){
        dist[s[0]][s[1]][i]=0;
        que.push_back({s[0],s[1],i});
    }
    while(!que.empty()){
        state u=que.front();que.pop_front();
        rep(i,4){
            int nx=u.x+dx[i],ny=u.y+dy[i],cost=dist[u.y][u.x][u.dir]+(u.dir!=i?1:0);
            if(0<=ny&&ny<h&&0<=nx&&nx<w&&graph[ny][nx]=='.'&&dist[ny][nx][i]>cost){
                dist[ny][nx][i]=cost;
                if(u.dir!=i)que.push_back({ny,nx,i});
                else que.push_front({ny,nx,i});
            }
        }
    }
    int ans=INF;
    rep(i,4)chmin(ans,dist[t[0]][t[1]][i]);
    cout<<ans<<endl;
    return 0;
}
/*
priority_queueじゃTLEになってしまう
やはりdequeしかなさそう
*/