#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll INF=1e13+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

vector<string> Place(20);
vector<string> Copy(20);
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

vector<vector<bool> > C(10,vector<bool>(10,false));
vector<vector<bool> > seen(10,vector<bool>(10));

int Co=0,check=0;

void dfs(int h,int w){
    seen[h][w]=true;
    Co++;//島の数？

    for(int i=0;i<4;i++){
        int nh=h+dy[i];
        int nw=w+dx[i];

        if(nh<0||nh>=10||nw<0||nh>=10)continue;
        if(Copy[nh][nw]=='x')continue;
        if(seen[nh][nw]==true)continue;

        dfs(nh,nw);
    }
}

int main(){
    rep(i,10)cin>>Place[i];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Place[i][j]=='o')check++;
        }
    }
    check++;//一マスを陸地にするため。
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            Co=0;
            Copy=Place;
            seen=C;
            if(Place[i][j]=='x'){
                Copy[i][j]='o';
                dfs(i,j);
                if(Co==check){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

//a=97,z=122