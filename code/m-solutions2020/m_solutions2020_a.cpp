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
    int x,ans;
    cin>>x;
    if(400<=x&&x<600){
        ans=8;
    }else if(600<=x&&x<800){
        ans=7;
    }else if(800<=x&&x<1000)ans=6;
    else if(1000<=x&&x<1200)ans=5;
    else if(1200<=x&&x<1400)ans=4;
    else if(1400<=x&&x<1600)ans=3;
    else if(1600<=x&&x<1800)ans=2;
    else if(1800<=x&&x<2000)ans=1;
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122