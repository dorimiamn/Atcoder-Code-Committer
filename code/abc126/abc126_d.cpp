// http://drken1215.hatenablog.com/entry/2019/05/19/224500
//参考にさせて頂いた解説
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll INF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;
Graph G;
int N;

vector<int> res;

void DFS(int v,int p,int c){
    res[v]=c;
    for(auto e:G[v]){
        if(e.first==p)continue;//次頂点が親である場合スルー
        if(e.second & 1) DFS(e.first,v,1-c);//e.second&1はbitで奇数判定を行っている。奇数の時は色を変えている。
        else DFS(e.first,v,c);//奇数でないためcolorはそのまま
    }
}

int main(){
    cin>>N;
    G.assign(N,vector<Edge>());
    //入力受け取り
    for(int i=0;i<N-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }
    res.assign(N,0);
    DFS(0,-1,1);//0は頂点を選択するため、-1は親がないため、1は色をつけるため。
    for(auto v: res) cout<<v<<endl;
    return 0;
}

//a=97,z=122

//頂点に色を設定し、そこから行ける頂点の辺の距離が偶数であれば、同色を設定し、奇数であれば、違う色？
//辺と頂点のリンクの仕方はどうしよう？