/*
https://o-treetree.hatenablog.com/entry/ABC173
勉強させて頂いた解説
最大値を取れる場所一つと引き換えに、
新しく二つ値が取れる場所を挿入するというのは、
思いつかなかった……
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
    int n,m=INF;
    ll ans=0;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(ALL(a),greater<ll>());
    /*
    priority_queueを使わなくても、数列はsortされているため、
    取り出す値は最大値であることが保証されているため、
    queuegが使える。
    */
    queue<ll> que;
    rep(i,n){
        if(i==0){
            que.push(a[i]);
        }else{
            ans+=que.front();
            que.pop();
            que.push(a[i]);
            que.push(a[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122