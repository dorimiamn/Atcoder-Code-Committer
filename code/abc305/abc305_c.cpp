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
    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    rep(i,H)cin>>S[i];

    rep(y,H){
        rep(x,W){
            if(S[y][x]=='.'){
                //凹み
                int sum=0;
                rep(i,4){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx<0||W<=nx||ny<0||H<=ny)continue;
                    if(S[ny][nx]=='#')sum++;
                }
                if(sum>=2){
                    cout<<y+1<<" "<<x+1<<endl;
                    return 0;
                }

            }
        }
    }

    return 0;
}
//凹みと、角のかけで判定は変えられそう。