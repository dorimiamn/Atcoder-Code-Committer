//https://snuke.hatenablog.com/entry/20110214/1297674577
//大変ありがたく、参考にさせて頂いた解説

#include <bits/stdc++.h>
#include <cstdio>

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
#define rrep(i,n) for(int i=1;i<=(n);i++)
#define pb push_back


int dp[2000];

int main(){
    int n,k,c,g;
    cin>>n>>k;

    vector<vector<int> > b(11),v(11);

    rep(i,n){
        cin>>c>>g;
        b[g].pb(c);//ジャンルごとに本を挿入
    }

    rrep(i,10){
        sort(b[i].begin(),b[i].end(),greater<int>());//各ジャンルごとに降順にソート
        v[i].pb(0);//配列vはiジャンルのj冊目までを打ったときの値段を入れるため、0冊の時を0で初期化。また、ソートしているため、それぞれの値が最高の収入を示す
    }

    rrep(i,10)rep(j,b[i].size())v[i].pb(v[i][j]+b[i][j]+j*2);//ジャンルごとに、n冊売った時の値段をメモ。

    rrep(i,10){//ジャンル
        for(int j=k;j>=0;j--){//上限何冊売るか。
            for(int h=max(0,j-(int)v[i].size()+1);h<j;h++){//hはiジャンルの冊数に基づいて、決められる。
                dp[j]=max(dp[j],dp[h]+v[i][j-h]);
            }
        }
    }

    /*
    dp[h]+v[i][j-h]はh冊まで売った時の最大値に、iジャンルの本をここでの上限jに達する冊数買った時の値段を足している。
    自力でやろうとして、詰まったのは一つのジャンルだけでしか合計買取価格を出せないとなってしまったこと。
    ジャンルごとにある冊数まで買ったときの最大値を求め、それを用いてj冊の最大値を求めるという発想が出てこなかった……。
    面倒そうに見える制約？があれば下処理をすることを考える？
    配列dpはジャンルを重ねるごとにある冊まで買った時の最大値が更新される。
    */

    cout<<dp[k]<<endl;

    return 0;
}

//a=97,z=122