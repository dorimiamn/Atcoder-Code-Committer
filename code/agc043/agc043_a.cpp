/*
https://atcoder.jp/contests/agc043/submissions/11062955
勉強させていただいた提出
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1};
const int dy[]={1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int H,W;

bool isIn(int y,int x){
    return (0<=x&&x<W&&0<=y&&y<H);
}

int main(){
    cin>>H>>W;
    vector<string> s(H);
    vii dist(H+10,vi(W,INF));
    dist[0][0]=0;
    rep(i,H)cin>>s[i];
    if(s[0][0]=='#')dist[0][0]=1;
    queue<pair<int,int>> que;

    que.push({0,0});

    while(!que.empty()){
        int y=que.front().first,x=que.front().second;

        que.pop();

        rep(i,2){
            int nx=x+dx[i],ny=y+dy[i];
            if(isIn(ny,nx)&&(s[ny][nx]=='#'&&s[y][x]=='.')&&dist[ny][nx]>dist[y][x]+1){
                dist[ny][nx]=dist[y][x]+1;
                que.push({ny,nx});
            }else if(isIn(ny,nx)&&!(s[ny][nx]=='#'&&s[y][x]=='.')&&dist[ny][nx]>dist[y][x]){
                dist[ny][nx]=dist[y][x];
                que.push({ny,nx});
            }
            
        }
    }

    cout<<dist[H-1][W-1]<<endl;

    return 0;
}

//a=97,z=122
