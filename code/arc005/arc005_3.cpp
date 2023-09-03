#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int H,W;
    cin>>H>>W;
    vector<string> way(H);
    rep(i,H)cin>>way[i];

    int sx=-1,sy=-1,gx=-1,gy=-1;
    rep(i,H){
        rep(j,W){
            if(way[i][j]=='s')sx=j,sy=i;
            else if(way[i][j]=='g')gx=j,gy=i;
        }
    }
    deque<pair<int,int> >que;
    vector<vector<int> > dist(H,vector<int>(W,-1));
    dist[sy][sx]=0;
    que.push_front(make_pair(sy,sx));
    while(!que.empty()){
        int y=que.front().first;
        int x=que.front().second;
        que.pop_front();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0||ny>=H||nx<0||nx>=W)continue;

            if(way[ny][nx]=='#'&&dist[y][x]==2)continue;

            if(dist[ny][nx]!=-1)continue;

            if(way[ny][nx]=='#'){
                dist[ny][nx]=dist[y][x]+1;
                que.push_back(make_pair(ny,nx));
            }else{
                dist[ny][nx]=dist[y][x];
                que.push_front(make_pair(ny,nx));
            }
        }
    }
    if(dist[gy][gx]!=-1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

//a=97,z=122