/*
https://atcoder.jp/contests/abc021/submissions/2298208
https://qiita.com/nomikura/items/1518bc8a6e04d2580b0d
勉強させていただいた提出、記事
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

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()

template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

vector<vector<int>> G;
using modint=Fp<INF>;

int main(){
    int N,a,b,M;
    cin>>N>>a>>b>>M;
    a--,b--;
    G=vector<vector<int>>(N);
    rep(i,M){
        int x,y;
        cin>>x>>y;
        x--,y--;
        G[x].pb(y);
        G[y].pb(x);
    }
    vector<int> dist(111,INF);
    vector<modint>cnt(111,0);
    dist[a]=0;
    cnt[a]=1;
    queue<int> que;
    que.push(a);
    while(!que.empty()){
        int v=que.front();que.pop();
        if(v==b)break;//探査する頂点がbである時
        for(int t:G[v]){
            if(dist[t]==INF){
                dist[t]=dist[v]+1;
                que.push(t);
            }
            if(dist[t]==dist[v]+1){//頂点v->tが最短経路上にあるならvまでのカウントをたす.
                //v->tの経路は一つだが、vまでの経路は複数考えられるため。
                cnt[t]=cnt[t]+cnt[v];//こうすることによって最短経路を数え上げられる
            }
        }
    }

    cout<<cnt[b]<<endl;

    return 0;
}

//a=97,z=122