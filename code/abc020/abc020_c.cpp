/*
http://nocotan.github.io/%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0/2017/01/26/dijkstra-copy.html
http://mmxsrup.hatenablog.com/entry/2016/09/20/015201
勉強させていただいた記事
*/

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

//dijkstra法をmemoしながら使うことで始点から任意の頂点への最短距離を求めることが出来る。
//そのため、Gの位置をdijkstra関数内部で気にする必要性はない。

typedef tuple<ll,int,int> T;//tupleは任意の要素を指定できる型
ll sy,sx,gy,gx,h,w,t;
vector<string>S;

bool dijkstra(ll m){
    vector<vector<ll>>memo(12,vector<ll>(12,INF*2));
    priority_queue<T,vector<T>,greater<T>>q;
    q.push(make_tuple(0,sy,sx));
    memo[sy][sx]=0;
    while(!q.empty()){
        ll c;int y,x;
        tie(c,y,x)=q.top();q.pop();//tupleからの取り出しかた
        rep(i,4){
            int ny=y+dy[i],nx=x+dx[i];
            if(!(0<=ny&&ny<h&&0<=nx&&nx<w))continue;
            if(S[ny][nx]=='#'){//白か黒かで必要秒数が異なるため。
                if(memo[ny][nx]>c+m){
                    memo[ny][nx]=c+m;
                    q.push(make_tuple(c+m,ny,nx));
                }
            }else{
                if(memo[ny][nx]>c+1){
                    memo[ny][nx]=c+1;
                    q.push(make_tuple(c+1,ny,nx));
                }
            }
        }
    }
    if(memo[gy][gx]<=t)return true;
    else return false;
}

int main(){
    cin>>h>>w>>t;
    rep(i,h){
        string s;
        cin>>s;
        S.pb(s);
    }
    rep(i,h){
        rep(j,w){
            if(S[i][j]=='S')sx=j,sy=i;
            else if(S[i][j]=='G')gx=j,gy=i;
        }
    }

    ll l=1,r=INF;

    while(r-l>1){//にぶたん
        int x=(l+r)/2;
        if(dijkstra(x))l=x;
        else r=x;
    }
    cout<<l<<endl;

    return 0;
}

//a=97,z=122