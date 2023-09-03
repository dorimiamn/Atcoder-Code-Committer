//https:tdpc.contest.atcoder.jp/submissions/7578635
//参考にさせていただいたコード

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <cstring>
#include <iomanip>


using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

//備忘録1.min()ではllは使えない

int main(){
    ll N,D; // 問題文はよく読んで範囲に注意すべし……
    cin>>N>>D;

    int A=0,B=0,C=0;
    while(D%2==0)A++,D/=2;
    while(D%3==0)B++,D/=3;
    while(D%5==0)C++,D/=5;

    if(D>1){
        cout<<0<<endl;
        return 0;
    }

    //備忘録2.
    //dpの添字にはDに含まれる2,3,5の素因数をそれぞれ使う？
    //そうすることによってかける必要性はなくなる。
    //2,3,5を添字にしてセーフなのか？
    //と思ったが、それぞれの個数でかけた数がわかるので問題ない。
    //すごいとしか言えない……
    //dpの、ある配列に直接確率を入れることができるのは
    //なぜ？
    //tmp定義の時点で、dpの、ある配列に格納されている確率と6分の１をかけているため？
    /*と納得
    また、dpテーブルの部分でminを持ているのはj,k,lの飛び出しを防ぐため？
    なら元から引いても良いのでは？無理だった
    1~6の確率では123456を素因数で表した時のj,k,lを数を用いている？
    */
    
    double dp[N+1][A+1][B+1][C+1];
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=1.0;
    for(int i=0;i<N;i++){
        for(int j=0;j<=A;j++){
            for(int k=0;k<=B;k++){
                for(int l=0;l<=C;l++){
                    double tmp=(1.0/6.0)*dp[i][j][k][l];
                    //1~6の確率
                    dp[i+1][j][k][l]+=tmp;
                    dp[i+1][min(j+1,A)][k][l]+=tmp;
                    dp[i+1][j][min(k+1,B)][l]+=tmp;
                    dp[i+1][min(j+2,A)][k][l]+=tmp;
                    dp[i+1][j][k][min(l+1,C)]+=tmp;
                    dp[i+1][min(j+1,A)][min(k+1,B)][l]+=tmp;
                }
            }
        }
    }
    //備忘録3.小数点以下の出力扱いでは精度に気をつける。
    cout<<setprecision(10)<<dp[N][A][B][C]<<endl;
    return 0;
}