//http://mmxsrup.hatenablog.com/entry/2017/04/20/142707
//勉強にさせて頂いた記事

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

//求めるものは1の個数

int main(){
    string A;
    cin>>A;

    ll dp[20][2][20]={0};

    dp[0][0][0]=1;

    int L=A.size();

    //dp[i][j][k]からの遷移を考える
    //なぜ、数え上げの時は、遷移元を遷移先に足すんだ？
    //遷移元はバラバラだったのが一つの遷移先に固まるから、足す？

    rep(i,L){
        rep(j,2){
            rep(k,i+1){
                if(dp[i][j][k]==0)continue;//貰うDPなので、貰うところに値がない時は飛ばす
                //上の文がないと値が小さくなってしまう。値入りの場所を0初期化してしまうことがあるから？
                if(j==1){//N未満かどうか
                    dp[i+1][1][k+1]+=dp[i][j][k];
                    dp[i+1][1][k]+=dp[i][j][k]*9;//自由なので0,2~9によって新しくできる数の通りを代入
                }else{//そうでない時
                    if(A[i]=='1'){//A[i]が1で、N未満フラグの更新を別途しなければいけない時
                        dp[i+1][0][k+1]+=dp[i][j][k];//上限である、1を選択した時
                        dp[i+1][1][k]+=dp[i][j][k];
                    }else if(A[i]=='0'){//何も選択できない時
                        dp[i+1][0][k]+=dp[i][j][k];
                    }else{//それ以外
                        dp[i+1][0][k]=dp[i][j][k];//Nに沿っている時
                        dp[i+1][1][k]=dp[i][j][k]*((A[i]-'0')-1);//使える数字の数、今までの通りとかけてi+1桁で何通りあるか？
                        dp[i+1][1][k+1]+=dp[i][j][k];//1を書く時
                    }
                }
            }
        }
    }
    ll ANS=0;
    rep(j,2)rep(k,12){
        if(dp[(int)A.size()][j][k]){
            ANS+=k*dp[int(A.size())][j][k];//k個1*その通りの数で、書く1の数を出している
        }
    }

    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122