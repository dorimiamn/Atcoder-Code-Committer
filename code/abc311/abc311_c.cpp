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

// 辺を表す構造体
template<class T> struct Edge {
    int from, to;
    T val;
    Edge(int f = -1, int t = -1, T v = -1) : from(f), to(t), val(v) {}
};

// グラフを表す型
template<class T> using Graph = vector<vector<Edge<T>>>;

// サイクル検出ソルバー
template<class T> struct CycleDetection {
    // 入力されたグラフ
    Graph<T> G;
    
    // 探索の様子
    vector<bool> seen, finished;
    vector<Edge<T>> history;
    
    // コンストラクタ
    CycleDetection() { }
    CycleDetection(const Graph<T> &graph) { init(graph); }
    void init(const Graph<T> &graph) {
        G = graph;
        seen.assign(G.size(), false);
        finished.assign(G.size(), false);
    }
    
    // サイクル検出
    // return the vertex where cycle is detected
    int dfs(int v, const Edge<T> &e, bool is_prohibit_reverse = true) {
        seen[v] = true;    // 行きがけ時に true になる
        history.push_back(e);    // 履歴を残す
        for (const Edge<T> &e2 : G[v]) {
            // 逆流を禁止する場合は逆流を禁止する
            if (is_prohibit_reverse && e2.to == e.from) continue;
            
            // 頂点 v2 がすでに探索済みの場合はスキップ
            if (finished[e2.to]) continue;

            // サイクルが検出された
            if (seen[e2.to] && !finished[e2.to]) {
                history.push_back(e2);
                return e2.to;
            }

            // 頂点 v2 を再帰的に探索する
            int pos = dfs(e2.to, e2, is_prohibit_reverse);
            if (pos != -1) return pos;
        }
        finished[v] = true;    // 帰りがけ時に true になる
        history.pop_back();    // 探索が完全に終了した頂点 (赤色) は履歴から除去する
        return -1;
    }
    
    // 履歴からサイクルのみを抽出する関数 (pos：サイクルを検出した頂点)
    vector<Edge<T>> reconstruct(int pos) {
        vector<Edge<T>> cycle;
        
        // 履歴を遡ってサイクルを形作る
        while (!history.empty()) {
            const Edge<T> &e = history.back();
            cycle.push_back(e);
            history.pop_back();
            if (e.from == pos) break;
        }
        
        // サイクルの向きを正順にする
        reverse(cycle.begin(), cycle.end());
        return cycle;
    }
    
    // サイクルを返す関数 (is_prohibit_reverse は逆流を許さないかどうか)
    vector<Edge<T>> detect(bool is_prohibit_reverse = true) {
        int pos = -1;
        for (int v = 0; v < (int)G.size() && pos == -1; ++v) {
            if (seen[v]) continue;
            history.clear();
            pos = dfs(v, Edge<T>(), is_prohibit_reverse);
            if (pos != -1) return reconstruct(pos);
        }
        return vector<Edge<T>>();
    }
};

int main(){
    int N;
    cin>>N;
    Graph<int> graph(N+1);
    rep(i,N){
        int x;
        cin>>x;
        graph[i].pb(Edge(i,x-1,1));
    }
    CycleDetection<int> cd(graph);
    const vector<Edge<int>> &res=cd.detect(false);

    cout<<res.size()<<endl;
    for(const Edge<int> &e:res){
        cout<<e.to+1<<endl;
    }
    return 0;
}
/*

*/