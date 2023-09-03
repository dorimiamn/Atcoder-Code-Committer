/*
https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
勉強させていただいた記事
*/

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

    UnionFind tree(N);

    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        tree.unite(a,b);
    }
    int cnt=0;
    rep(i,N){
        if(!tree.same(0,i)){
            cnt++;
            //木が何個あるか数えるなんてどうしたものかと思ったが、
            //実際に結合してやればいいは思いつかなんだ
            tree.unite(0,i);
        }
    }
    cout<<cnt<<endl;

    return 0;
}

//a=97,z=122