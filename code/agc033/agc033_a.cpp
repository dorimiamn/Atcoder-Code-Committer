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

    vector<vector<int> >dist(H,vector<int>(W,-1));
    queue<pair<int,int> >que;
    rep(i,H){
        rep(j,W){
            if(way[i][j]=='#'){
                que.push(make_pair(i,j));
                dist[i][j]=0;
            }
        }
    }
    while(!que.empty()){
        int y=que.front().first;
        int x=que.front().second;
        que.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0||ny>=H||nx<0||nx>=W)continue;

            if(dist[ny][nx]!=-1)continue;

            dist[ny][nx]=dist[y][x]+1;
            que.push(make_pair(ny,nx));
        }
    }
    int M=0;
    rep(i,H){
        rep(j,W)if(M<dist[i][j])M=dist[i][j];
    }
    cout<<M<<endl;
    return 0;
}

//a=97,z=122