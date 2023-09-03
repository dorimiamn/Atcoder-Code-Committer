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
    int R,C;
    ll ans=0;
    cin>>R>>C;
    vii s(R,vi(C));
    rep(i,R)rep(j,C)cin>>s[i][j];

    for(int bit=0;bit<(1<<R);bit++){
        vector<bool> ord(R,0);
        int N=0;
        ll sum=0;
        rep(i,R){
            if(bit&(1<<i))ord[i]=true;
            else ord[i]=false;
        }
        rep(c,C){
            int o=0,u=0;
            rep(r,R){
                if(ord[r]){
                    if(s[r][c]==0)o++;
                    else u++;
                }else{
                    if(s[r][c]==1)o++;
                    else u++;
                }
            }
            if(o>u)sum+=o;
            else sum+=u;
        }
        chmax(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122