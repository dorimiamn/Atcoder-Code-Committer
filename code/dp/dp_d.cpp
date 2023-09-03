#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <sstream>

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

ll dp[110][100100]={0};
ll weight[110],value[110];
ll N,W;

int main(){
    cin>>N>>W;
    rep(i,N)cin>>weight[i]>>value[i];

    rep(i,N){
        rep(j,W+1){
            if(j-weight[i]>=0){
                chmax(dp[i+1][j],dp[i][j-weight[i]]+value[i]);
            }
            chmax(dp[i+1][j],dp[i][j]);
        }
    }

    cout<<dp[N][W]<<endl;
    return 0;
}
//自力を目指したがhttps://qiita.com/drken/items/dc53c683d6de8aeacf5a#d-問題---knapsack-1を写経