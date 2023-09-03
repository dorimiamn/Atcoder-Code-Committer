//https://emtubasa.hateblo.jp/entry/2019/06/12/170716
//勉強させて頂いた記事

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

//bitの性質
//1100=12,
//0011=3;
//1111=15　となることから(0,0),(0,1),(1,0)を考慮すれば良い

int main(){
    string A;
    cin>>A;
    int L=A.length();
    vector<vector<ll> > dp(L+1,vector<ll>(2,0));
    dp[0][0]=1;

    rep(i,L){
        if(A[i]-'0'==1){//dp[i][j]のjが0の時a+b=Lを表す。
            //自由に選べる時は(0,0),(1,0),(0,1)の通りがある。
            dp[i+1][1]+=dp[i][0]+dp[i][1]*3;//0にするとa+b<Lとなるのでj=1,また、そのまま加算
            dp[i+1][0]+=dp[i][0]*2;//そのため、A[i]がiになるには(1,0),(0,1)の二通りがあるので2をかける
        }else{
            dp[i+1][0]+=dp[i][0];//0の時、(0,0)しか選べないため
            dp[i+1][1]+=dp[i][1]*3;//自由に選んで良いため。
        }
        dp[i+1][1]%=INF;
        dp[i+1][0]%=INF;
    }

    cout<<(dp[L][0]+dp[L][1])%INF<<endl;

    return 0;
}

//a=97,z=122