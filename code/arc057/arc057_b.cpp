//http://mayokoex.hatenablog.com/entry/2016/07/10/101955
//勉強させて頂いた記事


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
    int N,K;
    cin>>N>>K;
    vector<int> sum(2222);
    vector<int> A(2222,0);
    rep(i,N){
        cin>>A[i];
        sum[i+1]=sum[i]+A[i];
    }
    if(K==sum[N]){
        cout<<1<<endl;
        return 0;
    }

    vector<vector<int> > dp(2222,vector<int>(2222,INF));//最小を求めたいからINF初期化

    dp[0][0]=0;
    rep(i,N){
        rep(j,i+1){
            if(dp[i][j>=INF])continue;//値が更新されている時のみというのを忘れていた
            //勝たない場合
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            //勝つ場合
            if(i==0){//例外処理、前の日が存在しないため、一回勝てば満たす
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
            }else{
                ll atleast=(ll)dp[i][j]*sum[i+1]/sum[i]+1;//勝率計算 分母に1加算することによって切り上げしている？ sumを記録するのは出てこなかった……
                if(atleast<=A[i]+dp[i][j]){//dp[i][j]/sum[i]+1で勝率計算の式それに試合数をかけることによって最低勝利数を求めている
                    dp[i+1][j+1]=min(dp[i+1][j+1],int(atleast));
                }//atleat<=A[i]+dp[i][j]で、その日に最大までで、atleastを満たす勝利数になるかを判定している
            }
        }
    }

    for(int i=N;i>=0;i--){
        if(dp[N][i]<=K){
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}

//a=97,z=122