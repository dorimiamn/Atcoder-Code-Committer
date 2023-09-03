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
    int N,D,ANS=0,MAX=0;
    cin>>D>>N;
    vector<int> day(D),A(N),B(N),C(N);

    rep(i,D)cin>>day[i];
    rep(i,N){
        cin>>A[i]>>B[i]>>C[i];
    }
    vector<vector<int> > dp(D,vector<int>(N,-1));

    for(int i=0;i<N;i++){
        if(A[i]<=day[0]&&day[0]<=B[i])dp[0][i]=0;
    }

    for(int i=0;i<D-1;i++){
        for(int j=0;j<N;j++){
            if(dp[i][j]>=0){
                for(int k=0;k<N;k++){
                    if(A[k]<=day[i+1]&&day[i+1]<=B[k]){
                        int a=abs(C[j]-C[k]);
                        if(dp[i+1][k]<dp[i][j]+a)dp[i+1][k]=dp[i][j]+a;
                    }
                }
            }
        }
    }

    int ans=-1;
    for(int i=0;i<N;i++){
        if(ans<dp[D-1][i])ans=dp[D-1][i];
    }

    cout<<ans<<endl;

    return 0;
}

//a=97,z=122