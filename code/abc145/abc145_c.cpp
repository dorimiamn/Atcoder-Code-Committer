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
int N;
double Count=0;
vector<int> X(0),Y(0);
bool visit[9]={false};
//vは原点からの移動距離
void DFS(int v,double l,int Co){
    if(Co==N){
        Count+=l;
        return;
    }
    visit[v]=true;


    for(int i=0;i<N;i++){
        if(visit[i])continue;
        int a=X[i]-X[v],b=Y[i]-Y[v];
        double range=sqrt(a*a+b*b);
        DFS(i,range+l,Co+1);
    }
    visit[v]=false;
    return ;
}

int main(){
    cin>>N;
    X.resize(N),Y.resize(N);
    rep(i,N)cin>>X[i]>>Y[i];
    for(int i=0;i<N;i++){
        visit[i]=true;
        DFS(i,0,1);
        visit[i]=false;
    }

    double b=1;
    for(int i=2;i<=N;i++){
        b*=i;
    }

    cout<<setprecision(10)<<Count/b<<endl;

    return 0;
}

//a=97,z=122