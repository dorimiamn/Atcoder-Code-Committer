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
#include <unordered_map>

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

ll p[101]={0};


int main(){
    ll sum1=0,N;
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>p[i];
        sum1+=p[i];
    }
    ll dp[101][10010]={0};
    dp[0][0]=1;
    dp[0][p[0]]=1;
    for(int i=1;i<N;i++){
        rep(j,sum1+1){
            if(j-p[i]>=0)chmax(dp[i][j],dp[i-1][j-p[i]]);
            chmax(dp[i][j],dp[i-1][j]);
        }
    }
    sum1=0;
    rep(i,N*100){
        if(dp[N-1][i]){
            sum1++;
        }
    }
    cout<<sum1<<endl;
    return 0;
}

//参考https://tdpc.contest.atcoder.jp/submissions/7660282