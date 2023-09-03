/*
勉強させていただいたサイト
二分探索の練習中
Aに対してBを二分探索すれば良いと考えたが計算量的に無理O(Nlog(N))が通るのか？となったが通るみたい
二分探索は無理では？
https://blog.hamayanhamayan.com/entry/2021/08/01/011957
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

int main(){
    int N,M;
    cin>>N>>M;
    vi a(N),b(M);
    rep(i,N)cin>>a[i];
    rep(i,M)cin>>b[i];

    sort(ALL(a));
    sort(ALL(b));

    int ans=INF;
    rep(i,N){
        int j=lower_bound(ALL(b),a[i])-b.begin();
        if(j<M)chmin(ans,abs(a[i]-b[j]));
        if(0<=j-1)chmin(ans,abs(a[i]-b[j-1]));
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/