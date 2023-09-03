/*
解説AC
https://atcoder.jp/contests/sumitrust2019/submissions/8683667
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
    ll n,ans=1;
    cin>>n;
    vi a(n),c(3,0);
    rep(i,n)cin>>a[i];
    rep(i,n){
        //idでどのcounterを進めるかを決めている
        //配列cを使って赤、青、緑の人が何人かを管理している。
        //a[i]に合致するものを探すのに合わせて計算して問題ない
        //わざわざ配列を使ってシミュレートするより楽
        //思いつかなかった......
        ll cnt=0,id=-1;
        if(a[i]==c[0]){cnt++;id=0;}
        if(a[i]==c[1]){cnt++;id=1;}
        if(a[i]==c[2]){cnt++;id=2;}
        if(id==-1){cout<<0<<endl;return 0;}
        ans*=cnt;
        c[id]++;
        ans%=INF;
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122