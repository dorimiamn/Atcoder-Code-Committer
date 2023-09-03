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
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int N;
    cin>>N;
    double sum=0;
    vector<double> a(N);
    rep(i,N){
        cin>>a[i];
        sum+=a[i];
    }


    double right=1e9,left=0;
    rep(_,100){
        double mid1=(right*2+left)/3,mid2=(right+left*2)/3;

        double res1,res2;
        res1=res2=0;

        rep(i,N){
            res1+=min(a[i],2*mid1);
        }
        res1=N*mid1+sum-res1;

        rep(i,N){
            res2+=min(a[i],2*mid2);
        }
        res2=N*mid2+sum-res2;

        // cout<<res1<<" "<<res2<<endl;

        if(res2>res1)left=mid2;
        else right=mid1;
        // cout<<right<<" : "<<left<<endl;
    }

    double ans=0;
    rep(i,N){
        ans+=min(a[i],2*right);
    }
    ans=N*right+sum-ans;
    ans/=N;

    cout<<decimal(10)<<ans<<endl;

    return 0;
}
/*

*/