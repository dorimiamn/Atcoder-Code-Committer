#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll INF=1e13+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
//↑各番号の中身が上下左右の移動に対応している

vector<string> field(0);

int H,W;

// 深さ優先探索
bool seen [510][510];//各マスが探索済みかどうか。
void dfs(int h,int w) {
    seen[h][w] = true; // v を訪問済にする

    //四方向の探索
    for(int dir=0;dir<4;dir++){
        int nh=h+dx[dir];
        int nw=w+dy[dir];

        if(nh<0||nh>=H||nw<0||nw>=W)continue;
        if(field[nh][nw]=='#')continue;

        //移動先が探索済みの場合
        if(seen[nh][nw])continue;

        dfs(nh,nw);
    }
}

int main(){
    cin>>H>>W;
    field.resize(H);
    for(int i=0;i<H;i++)cin>>field[i];
    //sとgを探す。
    int sh,sw,gh,gw;
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(field[h][w]=='s')sh=h,sw=w;
            if(field[h][w]=='g')gh=h,gw=w;
        }
    }

    //探索開始
    memset(seen,0,sizeof(seen));
    dfs(sh,sw);
    if(seen[gh][gw])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
//移動がどうなるかを考える？
//a=97,z=122