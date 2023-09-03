//解説AC

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

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()

int N,M;
vector<vector<bool>> G(50,vector<bool>(50,false));
vector<int> A(50),B(50);
vector<bool>visited(50);

void dfs(int v){
    visited[v]=true;
    rep(v2,N){
        if(G[v][v2]==false)continue;//繋がっていないなら
        if(visited[v2]==true)continue;//訪問済みなら
        dfs(v2);
    }
}


int main(){
    cin>>N>>M;

    rep(i,M){
        cin>>A[i]>>B[i];
        A[i]--,B[i]--;
        G[A[i]][B[i]]=G[B[i]][A[i]]=true;
    }
    int ANS=0;
    for(int i=0;i<M;i++){
        G[A[i]][B[i]]=G[B[i]][A[i]]=false;//取り除く

        rep(j,N)visited[j]=false;//初期化

        dfs(0);//visitedの更新

        bool bridge=false;
        rep(j,N)if(visited[j]==false)bridge=true;//一つでもtrueにされていなかったらそれは非連結にされたと言うことなので
        if(bridge)ANS++;

        G[A[i]][B[i]]=G[B[i]][A[i]]=true;//元に戻す
    }

    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122