//http://drken1215.hatenablog.com/entry/2019/02/04/013700
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

const int MAX_DIGIT=50;
ll dp[100][2];//i:桁,smaller:未満フラグ

int main(){
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];

    memset(dp,-1,sizeof(dp));//初期化
    dp[0][0]=0;//初期条件
    for(int d=0;d<MAX_DIGIT;d++){//dはdigitのd
        ll mask=1LL<<(MAX_DIGIT-d-1);//桁決め

        //Aで元々d桁目にビットが立っているものの個数
        int num=0;
        rep(i,N)if(A[i]&mask)++num;

        //Xのd桁目を0,1にした時のコスト
        ll cost0=mask*num;//1->0
        ll cost1=mask*(N-num);//0->1
        //maskにはbitの情報が入っていて、どこのbitかで値が決まるのでコストの計算が成り立つ

        //smaller-> smaller 未満なので自由に選択してよいため。
        if(dp[d][1]!=-1){
            chmax(dp[d+1][1],dp[d][1]+max(cost0,cost1));//0でも1でも自在に大きい方
        }

        //exact->smaller 上限を超えない処理をする
        if(dp[d][0]!=-1){
            if(K&mask){//Kのd桁目が1だったら、Xのd桁目は0に 超えないように0にしている？
                chmax(dp[d+1][1],dp[d][0]+cost0);//cost0は1->0の変換コストを表す。
            }
        }
        //exact->exact(Kにぴったり合わせる)
        if(dp[d][0]!=-1){
            if(K&mask)chmax(dp[d+1][0],dp[d][0]+cost1);//合わせるので、1の時は1,0の時は0
            else chmax(dp[d+1][0],dp[d][0]+cost0);
        }
    }
    //MAX_DIGITまで更新をかけているから、また未満フラグあり、なしの大きい方が解となる
    cout<<max(dp[MAX_DIGIT][0],dp[MAX_DIGIT][1])<<endl;


    return 0;
}

//a=97,z=122

//4=100
//1=001
//  101=5