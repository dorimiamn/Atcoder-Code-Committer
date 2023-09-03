#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)
#define mkp(a,b) make_pair(a,b)


int main(){
    vector<pair<double,double>> p(3);
    rep(i,3){
        double x,y;
        cin>>x>>y;
        p[i]=mkp(x,y);
    }
    double a=p[0].first,b=p[0].second;
    rep(i,3)p[i].first-=a,p[i].second-=b;
    cout<<decimal(3)<<abs(p[1].first*p[2].second-p[1].second*p[2].first)/2<<endl;
    return 0;
}

//a=97,z=122