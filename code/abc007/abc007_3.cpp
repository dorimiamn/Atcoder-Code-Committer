#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int R,C,sy,sx,gy,gx;
    cin>>R>>C>>sy>>sx>>gy>>gx;
    sy--,sx--,gy--,gx--;
    vector<string> way(R);
    rep(i,R)cin>>way[i];

    vector<vector<int> > dist(R,vector<int>(C,-1));

    queue<pair<int,int> > que;
    dist[sy][sx]=0;
    que.push(make_pair(sy,sx));
    while(!que.empty()){
        int y=que.front().first;
        int x=que.front().second;
        que.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||nx>=C||ny<0||ny>=R)continue;

            if(dist[ny][nx]!=-1)continue;//親に戻らせない処理
            if(way[ny][nx]=='#')continue;
            que.push(make_pair(ny,nx));
            dist[ny][nx]=dist[y][x]+1;
        }
    }
    cout<<dist[gy][gx]<<endl;
    return 0;
}

//a=97,z=122