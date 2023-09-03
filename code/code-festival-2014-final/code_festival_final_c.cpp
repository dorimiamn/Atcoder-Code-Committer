#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=15000;
const int INF=1000000007;
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
    ll A;
    cin>>A;
    ll ok=LongINF,ng=10;
    while(ok-ng>1){
        ll mid=(ok+ng)/2,root,res=0,exp=1;
        root=mid;
        //n進数の変換
        while(mid){
            int x=mid%10;
            mid/=10;
            res+=x*exp;
            exp*=root;
        }
        // cout<<res<<endl;
        if(res>=A)ok=root;
        else ng=root;
        // cout<<ok<<" "<<ng<<endl;
    }
    ll root=ok,res=0,exp=1;
    while(ok){
        int x=ok%10;
        ok/=10;
        res+=x*exp;
        exp*=root;
    }
    if(res==A)cout<<root<<endl;
    else cout<<-1<<endl;
    return 0;
}
/*
n進数でnと表現できる数は単調に増加していくので、二分探索を用いて求められるはず？
*/