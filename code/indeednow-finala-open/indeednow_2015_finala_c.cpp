#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> x(M),y(M),z(M);
    int dp[103][103][103]={0};
    rep(i,N){
        int a,b,c,w;
        cin>>a>>b>>c>>w;
        dp[a][b][c]=max(w,dp[a][b][c]);
    }
    rep(i,M)cin>>x[i]>>y[i]>>z[i];

    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            for(int k=0;k<101;k++){
                if(i>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
                if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
                if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]);
            }
        }
    }
    rep(i,M){
        cout<<dp[x[i]][y[i]][z[i]]<<endl;
    }
    return 0;
}

//a=97,z=122