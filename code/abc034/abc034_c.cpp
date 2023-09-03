//http://drken1215.hatenablog.com/entry/2018/06/08/210000
//勉強させていただいた記事

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

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int a, int b){
    if (a < 0 || b < 0) return 0;
    return fac[a+b-2] * (finv[a-1] * finv[b-1] % MOD) % MOD;
}

//nCk=(n!)*(k!)^-1*((n-k)!)^-1を利用している facがn!,finvがk!^-1であるinvはそれらを計算するためのもの
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()

int main(){
    int W,H;
    cin>>W>>H;
    COMinit();

    cout<<COM(W,H)<<endl;
    //二項係数を流用して、nCkについて言及した式で、kとn-kをW-1,H-1に置き換えている

    return 0;
}
