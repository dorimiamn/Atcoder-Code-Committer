#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={-1,-1,0,0,1,1};
const int dy[]={-1,0,-1,1,0,1};

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

int n,ans=0;
vector<vector<bool>> dist(3002,vector<bool>(3002,false));
vi X(1001),Y(1001);

bool isOutRange(int x,int key){
    if(0<=x&&x<key)return false;
    return true;
}

void dfs(int y,int x){
    rep(i,6){
        int nx=x+dx[i],ny=y+dy[i];
        if(isOutRange(nx,2001)||isOutRange(ny,2001))continue;
        if(dist[ny][nx])continue;
        rep(j,n){
            if(nx==X[j]&&ny==Y[j]){
                dist[ny][nx]=true;
                dfs(ny,nx);
                break;
            }
        }
    }
}

int main(){
    cin>>n;
    rep(i,n){
        cin>>X[i]>>Y[i];
        X[i]+=1000,Y[i]+=1000;
    }
    rep(i,n){
        if(dist[Y[i]][X[i]])continue;
        ans++;
        dfs(Y[i],X[i]);
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/