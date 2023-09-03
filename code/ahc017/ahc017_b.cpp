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
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

struct coordinates{
    int x;
    int y;
};

struct edge{
    int weight;
    int num;
    bool operator<(const edge& another) const {
        //メンバ変数であるnum1で比較した結果を
        //この構造体の比較とする
        return weight < another.weight;
    }
};

int main(){
    int n,m,d,k;
    cin>>n>>m>>d>>k;
    deque<edge> que;
    vector<edge>edges(m);
    vector<coordinates> points(m);
    vi construct_count(n,0);
    vii construct_day_count(n,vi(d+1,0)),vertex_edge(n);
    rep(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        edges[i]={w,i};
        points[i]={u,v};
        vertex_edge[u].pb(i);
        vertex_edge[v].pb(i);
    }
    sort(ALL(edges));
    rep(i,m){
        if(i%2==0)que.push_front({edges[i].weight,i});
        else que.push_back({edges[i].weight,i});
    }
    rep(i,n){
        int x,y;
        cin>>x>>y;
        // x--,y--;
        // points[i]={x,y};
    }
    vi ans(m);
    map<int,int>mp;
    int day=1,maxday=m/d,rem=m%d;
    while(!que.empty()){
        auto [weight,idx]=que.back();
        que.pop_back();
        if(mp[day]>=maxday){
            day++;
            //break時ans[idx]処理がされてなくて一つ0が出てたみたい
            if(day>d){
                que.push_back({weight,idx});
                break;
            }
        }
        mp[day]++;
        ans[idx]=day;
        construct_count[points[idx].x]++;
        construct_count[points[idx].y]++;
        construct_day_count[points[idx].x][day]++;
        construct_day_count[points[idx].y][day]++;
    }
    day=1;
    while(!que.empty()){
        auto [weight,idx]=que.back();
        if(weight<0)weight*=-1;
        que.pop_back();
        if(mp[day]>=k){
            que.push_back({weight,idx});
            continue;
        }
        mp[day]++;
        ans[idx]=day;
        //idxは辺の番号 頂点にしないといけない
        construct_count[points[idx].x]++;
        construct_count[points[idx].y]++;
        construct_day_count[points[idx].x][day]++;
        construct_day_count[points[idx].y][day]++;
        day=(day+1)%d+1;
    }
    int start_time=clock();
    rep(i,n){
        REP(j,1,d+1){
            if(construct_day_count[i][j]==construct_count[i]){
                bool find=false;
                while(clock()-start_time<8*CLOCKS_PER_SEC&&!find){
                    rep(i2,n){
                        if(!construct_count[i2])continue;
                        REP(j2,1,d+1){
                            if(construct_day_count[i2][j2]&&construct_day_count[i2][j2]<=construct_count[i2]){
                                int edge1=vertex_edge[i].front(),edge2=vertex_edge[i2].front();
                                int exchange_day=ans[edge1];
                                construct_day_count[i][ans[edge1]]--;
                                construct_day_count[i][ans[edge2]]++;
                                construct_day_count[i2][ans[edge2]]--;
                                construct_day_count[i2][ans[edge1]]++;
                                ans[edge1]=ans[edge2];
                                ans[edge2]=exchange_day;
                                find=true;
                                break;
                            }
                        }
                        if(find)break;
                    }
                }
            }
        }
    }
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    // rep(i,d)cout<<i+1<<"日目："<<mp[i+1]<<endl;
    return 0;
}
/*
ある頂点につながる辺が同日に工事されないようにするには？
頂点ごとに、日ごとの工事本数を記録して、全て工事していたら別のものと交換
これを時間制限内まで繰り返す
頂点が持つ辺の数を管理
交換可能なものと日にちを交換

223560534724
218853315560
133417496324
*/