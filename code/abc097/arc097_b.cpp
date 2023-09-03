/*
https://qiita.com/ofutonfuton/items/550c984f08e39a189ca6#d%E5%95%8F%E9%A1%8C
勉強させていただいた記事
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

struct UnionFind{
vi par;
UnionFind(int N) : par(N){
   rep(i,N)par[i]=i;
}

int root (int x){
   if(par[x]==x)return x;
   return par[x]=root(par[x]);
}

void unite(int x,int y){
int rx=root(x);
int ry=root(y);
if(rx==ry)return;
par[rx]=ry;
}

bool same(int x,int y){
   int rx=root(x);
   int ry=root(y);
return rx==ry;
}
};

int main(){
    int N,M;
    cin>>N>>M;
    vi p(N);
    rep(i,N)cin>>p[i];

    UnionFind tree(N);
    rep(i,M){
        int x,y;
        cin>>x>>y;
        tree.unite(x-1,y-1);
    }

    int cnt=0;
    rep(i,N){
        if(tree.same(i,p[i]-1)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

//a=97,z=122