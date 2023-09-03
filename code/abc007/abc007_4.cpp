//https://torus711.hatenablog.com/entry/20150423/1429794075
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

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back


ll solve(const string &S){
    ll dp[30][2][2]={0};//第二添字は選択時の最大値であるかどうか、第三添字は4,9が含まれていないかどうか。

    int L=S.size();
    
    dp[0][0][0]=1;

    for(int i=0;i<L;i++){//桁数
        int D=S[i]-'0';
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int d=0;d<=(j?9:D);d++){
                    dp[i+1][j||(d<D)][k||d==4||d==9]+=dp[i][j][k];
                }
            }
        }
    }
    return dp[L][0][1]+dp[L][1][1];//選択時最大とそうでないものの和を返す、また、返すものは4,9が含まれているかどうかなので、[1]を返す
}

int main(){
    ll A,B;
    cin>>A>>B;
    cout<<solve(to_string(B))-solve(to_string(A-1))<<endl;

    return 0;
}

//a=97,z=122