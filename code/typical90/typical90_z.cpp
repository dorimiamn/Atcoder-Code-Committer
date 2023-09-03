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

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

void dfs(int n,int pos,vii& graph,vi& color){
    for(auto x:graph[pos]){
        if(color[x]!=-1)continue;
        color[x]=(color[pos]+1)%2;
        dfs(n,x,graph,color);
    }
}

int main(){
    int n;
    cin>>n;
    vii graph(n,vi(0)),ans(2,vi(0));
    vi color(n,-1);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    color[0]=0;
    dfs(n,0,graph,color);
    rep(i,n){
        if(color[i])ans[0].pb(i);
        else ans[1].pb(i);
    }
    rep(i,2){
        if(ans[i].size()>=n/2){
            int cnt=0;
            for(auto x:ans[i]){
                cout<<x+1;
                cnt++;
                if(cnt==n/2){
                    cout<<endl;
                    return 0;
                }else cout<<" ";
            }
        }
    }
    return 0;
}
/*
頂点と隣接する頂点を別々のグループに
6
1 3
2 3
3 4
3 5
3 6

問題ケース

二部グラフの性質か!
*/