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

//方針　dp
//テーブルには回数を保持させる
// j点にするのに最小の問題数を求める

int main(){
    int D,G,MAX=0;
    cin>>D>>G;
    G/=100;

    vector<pair<int,int> > PC(D);
    rep(i,D){
        int a,b;
        cin>>a>>b;
        b/=100;
        MAX=MAX+(i+1)*a+b;
        PC[i]=make_pair(a,b);
    }

    /*
    どんなテーブルが必要か、i,jでi問目を解く時、j点にする最小の手数を考える。
    この時jは最大点である
    遷移式は？
    dp[i+1][j]=min(dp[i][j-a],dp[i][j])これじゃね？
    いやでもこれじゃ何問解くべきかわからない。
    足していく必要がある。
    if(j-a>=0)dp[i+1][j]=dp[i][j-a]+1;
    chmin(dp[i+1][j],dp[i+1][j])
    こうじゃないか？
    初期化INFかな
    comを考える必要はあるけど、大体はこれな気がする
    */

    vector<vector<int> > dp(11,vector<int>(205000,INF));
    dp[0][0]=0;

    for(int i=0;i<D;i++){
        int a=PC[i].first,b=PC[i].second;
        for(int j=1;j<=a;j++){
            int p=j*(i+1);
            if(j==a)p+=b;
            for(int k=0;k<=MAX;k++){
                if(k-p>=0)dp[i+1][k]=dp[i][k-p]+j;
                chmin(dp[i+1][k],dp[i][k]);
            }
        }
    }

    int ANS=INF;
    for(int i=G;i<=MAX;i++){
        ANS=min(dp[D][i],ANS);
    }
    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122