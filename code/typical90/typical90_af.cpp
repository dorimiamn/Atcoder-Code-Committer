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
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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
    int n,m,ans=INF;
    cin>>n;
    vii a(n,vi(n));
    rep(i,n)rep(j,n)cin>>a[i][j];
    cin>>m;
    vector<pair<int,int>> r(m);
    vi p(n,0);
    rep(i,m){
        cin>>r[i].first>>r[i].second;
        r[i].first--,r[i].second--;
    }
    rep(i,n)p[i]=i;
    do{
        int sum=0;
        rep(i,n){
            sum+=a[p[i]][i];
            if(i==n-1)break;
            rep(j,m){
                if(r[j].first==min(p[i],p[i+1])&&r[j].second==max(p[i],p[i+1])){
                    sum=-1;
                    break;
                }
            }
            if(sum==-1)break;
        }
        //cerr<<"sum:"<<sum<<endl;
        if(sum!=-1)chmin(ans,sum);
    } while (next_permutation(ALL(p)));
    if(ans==INF)ans=-1;
    cout<<ans<<endl;
    return 0;
}
/*

*/