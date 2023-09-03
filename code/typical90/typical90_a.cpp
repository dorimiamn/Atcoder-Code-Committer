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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

ll n,k,l;
ll a[1000000];

//二分探索で求めた値が成立するかcheck
//preは切る予定の場所
bool solve(ll m){
    int cnt=0,pre=0;
    rep(i,n+1){
        if(a[i]-pre>=m&&l-a[i]>=m){
            cnt+=1;
            pre=a[i];
        }
    }
    if(cnt>=k)return true;
    return false;
}

int main(){
    cin>>n>>l>>k;
    rep(i,n)cin>>a[i];
    ll left=-1,right=l+1;
    while(right-left>1){
        int mid=left+(right-left)/2;
        if(!solve(mid))right=mid;
        else left=mid;
    }
    cout<<left<<endl;
    return 0;
}
/*

*/