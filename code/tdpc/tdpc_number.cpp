//https://suikaba.hatenablog.com/entry/2017/07/03/033251
//勉強させて頂いた解説

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
    int D;
    string N;
    cin>>D>>N;
    int L=N.length();

    vector<vector<vector<ll>>> dp(N.size()+1, vector<vector<ll>>(D, vector<ll>(2)));
    dp[0][0][1]=1;
    reverse(N.begin(),N.end());

    for(int i=0;i<L;i++){
        int O=N[i]-'0';
        for(int j=0;j<D;j++){
            for(int k=0;k<2;k++){
                for(int d=0;d<=9;d++){
                    bool leq=d<(N[i]-'0')||k==1&&d==(N[i]-'0');
                    dp[i+1][(j+d)%D][leq]+=dp[i][j][k];//第2添字をどうしたらいいかがわからなかった……。
                    //余りに着目して考える。余りが0ならそれは和がDの倍数であることと変わらない
                    dp[i+1][(j+d)%D][leq]%=INF;
                }
            }
        }
    }

    cout<<(dp[L][0][1]-1)%INF<<endl;

    return 0;
}

//a=97,z=122