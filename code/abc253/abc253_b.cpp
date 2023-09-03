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
    int h,w;
    cin>>h>>w;
    vector<string>s(h);
    vector<vector<bool>> dist(h,vector<bool>(w,false));
    rep(i,h)cin>>s[i];
    int sx,sy;
    rep(i,h){
        rep(j,w)if(s[i][j]=='o'){
            sx=j,sy=i;
            break;
        }
    }
    queue<tuple<int,int,int>> que;
    que.push({sx,sy,0});
    dist[sy][sx]=true;
    while(!que.empty()){
        auto[x,y,cnt]=que.front();
        que.pop();
        rep(i,4){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||w<=nx||ny<0||h<=ny)continue;
            if(dist[ny][nx])continue;
            if(s[ny][nx]=='o'){
                cout<<cnt+1<<endl;
                return 0;
            }else{
                dist[ny][nx]=true;
                que.push({nx,ny,cnt+1});
            }
        }
    }
    return 0;
}
/*

*/