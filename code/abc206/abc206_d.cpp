//勉強させていただいた解説
//https://blog.hamayanhamayan.com/entry/2021/06/19/233819
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

struct UnionFind
{
    vi par;
    UnionFind(int N) : par(N, -1) {}
    int root(int x)
    {
        if (par[x] < 0)
            return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;
        if (par[x] == par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
    int size(int x)
    {
        return -par[root(x)];
    }
};

int main(){
    int N;
    cin>>N;
    vi a(N);
    UnionFind uf(2000000);
    rep(i,N)cin>>a[i];
    rep(i,N/2){
        //回文を作るために同じにならなければならない整数を結合している。
        uf.unite(a[i],a[N-i-1]);
    }

    int ans=0;
    //考えているのは値に対してだから、ループは数列aの値の上限であるべき
    rep(i,2000000){
        //i自身がが根であるものに対して
        if(uf.root(i)==i){
            //数字を変える操作には、連結成分の数-1回かかる
            ans+=uf.size(i)-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
数が異なる整数-１が答えになるのかなぁと思っていたが
それでは不十分そう

*/