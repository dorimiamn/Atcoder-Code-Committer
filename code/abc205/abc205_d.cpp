#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
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
    int N,Q;
    cin>>N>>Q;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];

    rep(i,Q){
        ll k,index=0;
        cin>>k;
        ll ok=N,ng=-1;
        while(ok-ng>1){
            ll mid=(ok+ng)/2;
            ll sum=a[mid]-mid-1;
            if(sum>=k)ok=mid;
            else ng=mid;
        }
        if(ok==0){
            cout<<k<<endl;
        }else if(ok==N){
            cout<<k+N<<endl;
        }else{
            cout<<ok+k<<endl;
        }
    }

    return 0;
}
/*

*/