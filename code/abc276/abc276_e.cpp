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

int H,W;

bool check(int x,int y){
    if(x<0||W<=x||y<0||H<=y)return true;
    return false;
}

bool dfs(int x,int y,int cnt,vector<string> &C,vector<vector<bool>> &dist){
    bool ans=false;
    rep(i,4){
        int nx=x+dx[i],ny=y+dy[i];
        if(check(nx,ny))continue;
        if(C[ny][nx]=='#')continue;
        if(dist[ny][nx])continue;
        if(C[ny][nx]=='S'){
            if(cnt<3)continue;
            return true;
        }
        dist[ny][nx]=true;
        ans=dfs(nx,ny,cnt+1,C,dist);
        if(ans)break;
        dist[ny][nx]=true;
    }
    return ans;
}

int main(){
    cin>>H>>W;
    vector<string> C(H);
    rep(i,H){
        cin>>C[i];
    }

    vector<vector<bool>> dist(H,vector<bool>(W));

    rep(i,H){
        rep(j,W){
            if(C[i][j]=='S'){
                if(dfs(j,i,0,C,dist)){
                    cout<<"Yes"<<endl;
                    return 0;
                }
                i=H,j=W;
            }
        }
    }

    cout<<"No"<<endl;

    return 0;
}
/*

*/