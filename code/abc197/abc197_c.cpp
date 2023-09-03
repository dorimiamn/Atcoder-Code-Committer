#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T,class Y> inline bool chmin(T& a, Y b) {if (a > b) {a = b;return true;}return false;}
template<class T,class Y> inline bool chmax(T& a, Y b) {if (a < b) {a = b;return true;}return false;}
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
    int n;
    cin>>n;
    vi a(n);
    ll res=LongINF;
    rep(i,n)cin>>a[i];
    for(int i=0;i<1<<(n-1);i++){
        int xored=0;
        int ored=0;
        for(int j=0;j<=n;j++){
            if(j<n)ored|=a[j];
            //仕切りを入れる場所で計算を挟んでる
            if(j==n||(i>>j&1))xored^=ored,ored=0;
        }
        chmin(res,xored);
    }
    cout<<res<<endl;
    return 0;
}
/*
仕切りを入れるか入れないかの関係かー！！！
解説AC
*/