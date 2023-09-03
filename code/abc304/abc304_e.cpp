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
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

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

    UnionFind uf(N+1);

    rep(i,M){
        int x,y;
        cin>>x>>y;
        uf.unite(x,y);
    }

    int K;
    cin>>K;
    set<pair<int,int>> st;
    vector<pair<int,int>> path(K);
    rep(i,K){
        int x,y;
        cin>>x>>y;
        x=uf.root(x),y=uf.root(y);
        if(x>y)swap(x,y);
        st.insert({x,y});
        path[i]={x,y};
    }

    int Q;
    cin>>Q;
    rep(_,Q){
        int p,q;
        cin>>p>>q;
        p=uf.root(p),q=uf.root(q);
        if(p>q)swap(p,q);
        if(st.find({p,q})==st.end())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }


    return 0;
}
/*
UFを使うのは硬いと思う。
クエリが与えれたらO(1)で答えられるのが理想
つまり？与えられた各頂点が

条件の根を保存しておいて、
*/