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
    ll N,K,O=10000;
    cin>>N>>K;
    map<int,int> day;
    rep(i,K){
        int a,b;
        cin>>a>>b;
        day[a]=b;
    }

    vector<vector<vector<ll> > > dp(N+1,vector<vector<ll > >(3,vector<ll>(3,0)));
    
    dp[0][0][0]=1;
    if(day[1]==0){
        dp[1][0][0]=1;
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            if(day[i]!=0){
                int T=day[i]-1;
                if(j==T){
                    if(i==1){
                        dp[i][T][0]+=dp[i-1][j][0];
                    }else dp[i][T][1]=+dp[i-1][j][0];
                }else{
                    dp[i][T][0]+=dp[i-1][j][0];
                    dp[i][T][0]+=dp[i-1][j][1];
                }
            }else{
                int a=(j+1)%3,b=(j+2)%3;
                if(i!=1)dp[i][j][1]=dp[i-1][j][0];
                dp[i][j][0]+=dp[i-1][a][0];
                dp[i][j][0]+=dp[i-1][a][1];
                dp[i][j][0]+=dp[i-1][b][0]; 
                dp[i][j][0]+=dp[i-1][b][1];
            }
            dp[i][j][0]%=10000,dp[i][j][1]%=10000;
        }
    }

    ll ANS=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            ANS+=(dp[N][i][j]);
        }
    }

    cout<<ANS%10000<<endl;

    return 0;
}

//a=97,z=122