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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int h,w,q;

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

bool isOutRange(int x,int key){
    if(0<=x&&x<key)return false;
    return true;
}

int toNumber(int r,int c){
    int sum=0;
    sum+=w*(r-1)+c;
    return sum;
}

int main(){
    cin>>h>>w>>q;
    UnionFind uf(h*w+1);
    vector<vector<bool>> grid(h,vector<bool>(w,0));
    rep(i,q){
        int pattern;
        cin>>pattern;
        if(pattern==1){
            int r,c;
            cin>>r>>c;
            grid[r-1][c-1]=true;
            rep(j,4){
                if(isOutRange(c-1+dx[j],w)||isOutRange(r-1+dy[j],h))continue;
                if(grid[r-1+dy[j]][c-1+dx[j]])uf.unite(toNumber(r+dy[j],c+dx[j]),toNumber(r,c));
            }
        }else{
            int ra,ca,rb,cb;
            cin>>ra>>ca>>rb>>cb;
            if(grid[ra-1][ca-1]&&grid[rb-1][cb-1]&&uf.same(toNumber(ra,ca),toNumber(rb,cb)))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
/*
UnionFindで(ra,ca)と(rb,cb)が同じ集合かcheck
*/