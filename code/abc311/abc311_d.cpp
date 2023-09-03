#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
const int INF=1000000007;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

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
    int N,M;
    cin>>N>>M;
    vector<string> S(N);
    rep(i,N){
        cin>>S[i];
    }

    queue<tuple<int,int,int>> que;
    que.push({0,1,1});
    que.push({3,1,1});
    vector<vector<bool>> dist(N,vector<bool>(M,false));
    vector<vector<vector<bool>>> dist2(N,vector<vector<bool>>(M,vector<bool>(4,false)));
    while(que.size()){
        auto [to,y,x]=que.front();
        que.pop();
        dist[y][x]=true;
        dist2[y][x][to]=true;
        int ny=y+dy[to],nx=x+dx[to];
        if(S[ny][nx]=='#'){
            int cnt=0;
            rep(i,4){
                int nny=y+dy[i],nnx=x+dx[i];
                if(S[nny][nnx]=='.'&&(!dist[nny][nnx]||!dist2[nny][nnx][i])){
                    dist[nny][nnx]=true;
                    dist2[nny][nnx][i]=true;
                    que.push({i,nny,nnx});
                }
            }
        }else{
            que.push({to,ny,nx});
        }
    }
    int ans=0;
    rep(i,N){
        rep(j,M){
            // cout<<dist[i][j];
            if(dist[i][j]){
            ans++;
            }
        }
        // cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
通過時の方向を記録したほうがよさそう
氷はその方向にある岩を記録した座圧をすればよさそう

単純に座標と進行方向をもって、壁にぶつかったとき、周囲に移動できるマスがないかを探すべでは

4 4
####
#..#
#..#
####

*/