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

//解説AC

int main(){
    int N;
    int NG[3];
    cin>>N;
    rep(i,3)cin>>NG[i];
    rep(i,3){
        if(N==NG[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    vector<int> dp(N+1,INF);//dpに持たせる情報は数字kにたどり着くのに最低何手必要かを持たせる
    dp[N]=0;
    for(int i=N;i>=0;i--){
        if(NG[0]==i||NG[1]==i||NG[2]==i)continue;
        REP(j,1,4)if(i-j>=0)dp[i-j]=min(dp[i]+1,dp[i-j]);
    }
    if(dp[0]<=100)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

//a=97,z=122