/*
https://qiita.com/drken/items/ecd1a472d3a0e7db8dce#%E5%95%8F%E9%A1%8C-7abc-017-d-%E3%82%B5%E3%83%97%E3%83%AA%E3%83%A1%E3%83%B3%E3%83%88
勉強させていただいた記事
*/

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

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> F(N);
    rep(i,N)cin>>F[i],F[i]--;

    //尺取法
    vector<int> fnum(M,0);
    vector<int> L(N+1,0);//各iに対するしゃくとり法の区間
    int left=0;
    rep(right,N){
        fnum[F[right]]++;//rightが区間に入ったので足す
        while(left<right&&fnum[F[right]]>1){
            --fnum[F[left]];//left区間を縮める処理
            ++left;
        }
        L[right+1]=left;//rightにleftを入れているので、実質区間の長さ
    }

    //累積和で高速化したDP
    vector<int> dp(110000,0),sum(110000,0);
    //sum[i+1]はdp[0,i]と定義される
    sum[1]=1;
    REP(i,1,N+1){
        //sum[L[i]]はdp∑0~iである。またdp[i]はdp∑left~i-1のため
        /**
         * sum[i]-sum[L[i]]はdp[i]となる
         * また、累積和を用いることでdp[i]の値をとるのが楽になる。
         * 定義より、sumの更新はsum[i](dp[0,i-1])+dp[i]となる
        */
        dp[i]=(sum[i]-sum[L[i]]+INF)%INF;//DP
        sum[i+1]=(sum[i]+dp[i])%INF;//累積
    }
    cout<<dp[N]<<endl;

    return 0;
}

//a=97,z=122