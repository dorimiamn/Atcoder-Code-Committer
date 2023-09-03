//https://atcoder.jp/contests/abc015/submissions/8521468
//参考にさせて頂いたコード

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

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,W,K;
    cin>>W>>N>>K;
    vector<vector<ll> > dp(K+1,vector<ll>(W+1,0));

    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        for(int j=K;j>=0;j--){
            for(int k=W;k>=0;k--){
                if(j>=1&&k>=a)dp[j][k]=max(dp[j][k],dp[j-1][k-a]+b);
            }
        }
    }
    cout<<dp[K][W]<<endl;
    return 0;
}

//a=97,z=122