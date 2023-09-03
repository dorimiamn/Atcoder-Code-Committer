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

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)


int main(){
    ll a,b,n;
    cin>>a>>b>>n;
    ll ng=0,ok=n,ans=0;
    while(abs(ok-ng)>100){
        ll x=(ok+ng)/2;
        ll check=(a*x)/b-a*(x/b);
        if(ans>check){
            ok=x;
            //ans=check;
        }
        else{
            ng=x;
            ans=check;
        }
        //cout<<check<<" "<<x<<" "<<(a*x)/b<<" "<<a*(x/b)<<" ok-ng:"<<abs(ok-ng)<<endl;
    }
    //cout<<"end"<<endl;
    //cout<<ng<<" "<<ok<<endl;
    for(ll i=ng;i<ok+1;i++){
        //cout<<i-ng<<endl;
        ll num=(a*i)/b-a*(i/b);
        if(ans<num)ans=num;
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122