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

struct UnionFind{
    vi par;
    UnionFind(int N) : par(N,-1){ }
    
    int root (int x){
        if(par[x]<0)return x;
        return par[x]=root(par[x]);
    }
    
    void unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y)return;
        if(par[x]==par[y])swap(x,y);
        par[x]+=par[y];
        par[y]=x;
    }
    
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int size(int x){
        return -par[root(x)];
    }
};

int main(){
    int N,M;
    cin>>N>>M;
    UnionFind uf(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        uf.unite(a,b);
    }

    int ans=0;

    rep(i,N)chmax(ans,uf.size(i));

    cout<<ans<<endl;

    return 0;
}
/*
友達グループをUnionFindで求め、最大の大きさを持つグループの人数が解になるはず
各友達グループから１人ずつ出してグループを作っていけば条件を満たす。これを何回繰り返せばよいか？という問題なはずなので。
*/