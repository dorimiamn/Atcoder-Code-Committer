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

vi a(51,0),b(51,0),c(51,0),d(51,0);
ll M=0,n,m,q;

void dfs(int x,int n,vi arr){
    if(x==0){
        ll sum=0;
        rep(i,q){
            if(arr[a[i]]-arr[b[i]]==c[i])sum+=d[i];
        }
        //for(auto x:arr)cout<<x<<" ";
        //cout<<endl;
        M=max(sum,M);
    }else{
        for(int i=n;i>0;i--){
            vi a=arr;
            a.pb(i);
            dfs(x-1,i,a);
        }
    }
}

int main(){
    cin>>n>>m>>q;
    rep(i,q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--,b[i]--;
    }
    dfs(n,m,vi());
    cout<<M<<endl;
    return 0;
}

//a=97,z=122