//解説と回答例を参考にした

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)



int main(){
    int N;
    cin>>N;
    vector<vector<int>> G(N);
    vector<pair<int,int>> vp;

    for(int i=1;i<N;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        vp.emplace_back(a,b);
    }

    int K=0;//色の数
    map<pair<int,int>,int> I;
    vector<int> cs(N,0);//色を保管する

    vector<int> used(N,0);//探索済みか否かを保管する配列
    queue<int> que;
    used[0]=1;
    que.emplace(0);
    while(!que.empty()){//幅優先探索
        int v=que.front();que.pop();
        if(K<(int)G[v].size())K=G[v].size();//Kの数は隣接頂点の数あるため
        int cur=1;//色
        for(int u:G[v]){//辿れる頂点を探索
            if(used[u])continue;//色を塗ってあるなら
            if(cur==cs[v])cur++;//現在の色が探索元頂点塗ってある色と同色なら
            cs[u]=I[make_pair(u,v)]=I[make_pair(v,u)]=cur++;
            //色を塗りながら探索先頂点に色を塗る
            used[u]=1;
            que.emplace(u);
        }
    }
    cout<<K<<endl;
    for(auto p:vp)cout<<I[p]<<endl;
    return 0;
}

//a=97,z=122