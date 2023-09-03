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

vector<string> S(51);
int M = 0,H,W;
int dist[51][51];
queue<pair<int, int>> que;

int BFS(int sy,int sx)
{
    rep(i,51){
        rep(j,51)dist[i][j]=-1;
    }
    que.push(make_pair(sy, sx));
    dist[sy][sx] = 0;
    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        rep(i, 4)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx < 0 || nx >= W || ny < 0 || ny >= H)continue;
            if (S[ny][nx] == '#')continue;
            if (dist[ny][nx] != -1)continue;
            dist[ny][nx] = dist[y][x] + 1;
            M = max(M, dist[ny][nx]);

            que.push(make_pair(ny, nx));
        }
    }
    return 0;
}

int main(){
    cin>>H>>W;

    rep(i,H){
        cin>>S[i];
    }


    rep(sy,H){
        rep(sx,W){
            if(S[sy][sx]=='.')BFS(sy,sx);
        }
    }

    cout<<M<<endl;

    return 0;
}

//a=97,z=122

/*

4 5
#####
....#
.####
.....

*/