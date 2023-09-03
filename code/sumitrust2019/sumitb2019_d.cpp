//解説より

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
#define pb push_back

int main(){
    int N;
    string X;
    cin>>N>>X;

    bool dp[30009][4][1009];
    dp[0][0][0]=1;

    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<1000;k++){
                if(false==dp[i][j][k])continue;

                dp[i+1][j][k]=true;//選ばない
                if(j<=2){//選ぶ
                    dp[i+1][j+1][k*10+(X[i]-'0')]=true;
                }
            }
        }
    }int cnt=0;
    for(int i=0;i<1000;i++){
        if(true==dp[N][3][i])cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}

//a=97,z=122