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
    int N,M,K;
    cin>>N>>M>>K;
    vii graph(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vector<int> dist(N,-1);
    priority_queue<pair<int,int>>que;
    rep(i,K){
        int p,h;
        cin>>p>>h;
        p--;
        dist[p]=h;
        que.push({h,p});
    }

    while(!que.empty()){
        auto [h,p]=que.top();
        que.pop();
        if(dist[p]!=h)continue;
        for(auto np:graph[p]){
            if(dist[np]<h-1){
                dist[np]=h-1;
                que.push({dist[np],np});
            }
        }
    }

    int sum=0;
    vi ans;
    
    rep(i,N){
        if(dist[i]!=-1){
            sum++;
            ans.pb(i+1);
        }
    }
    cout<<sum<<endl;
    for(auto x:ans)cout<<x<<endl;
    return 0;
}
/*
警備員の体力順にダイクストラを行なって、各頂点を一回のみ訪問することで、計算量を落とせる？
方針は合っていた。
ダイクストラに持たせるのが、残り距離だった。えー悔しい
*/