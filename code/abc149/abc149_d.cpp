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


int main(){
    ll N,K,R,S,P;
    ll seed,getpoint=0,givepoint=0;
    ll seed2,givepoint2=0;
    string T;
    cin>>N>>K>>R>>S>>P>>T;
    //DP......?
    //回数、出した手　が引数？
    //K日前と同じものは出せないので、
    /*
    出せるものからの遷移を考えれば良いのでは？

    いや、K日前の結果を改竄……
    でも、影響あるのはその二日間しかない。
    ので、K日前の結果を改竄して、
    (K日前で加算したものを取り消し、別のものを足すこと、にする？)
    そもそも、同じ手を出したいとなるのは勝ちたい時だけだ
    Greedyでは？
    K個の列があると考えて調べていくべき
    

    でも集計結果はそれの影響をうける

    */
   /*
    vector<ll> Seeds(N,0);

   rep(i,K){
        bool c=false;
        ll Co=1;
        for(int j=i;j<N-K;j+=K){//最良手が連続してかつ、奇数回で会ったときはそれを採用
            if(T[j]=='r')seed1=0,givepoint1=P;
            else if(T[j]=='s')seed1=1,givepoint1=R;
            else seed1=2,givepoint1=S;
            

            if(T[j+K]=='r')seed2=0,givepoint2=P;
            else if(T[j+K]=='s')seed2=1,givepoint2=R;
            else seed2=2,givepoint2=S;

            if(seed1==seed2){
                Co++;
                c=true;
            }else if(c){
                c=false;
                if(Co%2==1){
                    getpoint+=givepoint1*((Co+1)/2);
                }else{
                    getpoint+=givepoint1*(Co/2);
                }
                Co=1;
            }else{
                getpoint+=givepoint1;
            }
        }
        if(c){
            if(Co%2==1){
                getpoint+=givepoint1*((Co+1)/2);
            }else{
                getpoint+=givepoint1*(Co/2);
            }
        }else{
            getpoint+=givepoint2;
        }
   }
    */

    vector<int> Seeds(N,4);
    rep(i,N){
        if(T[i]=='r')seed=0,givepoint=P;
        else if(T[i]=='s')seed=1,givepoint=R;
        else seed=2,givepoint=S;
        if(i>=K){
            if(Seeds[i-K]==seed)Seeds[i]=3;
            else if(Seeds[i-K]==3){
                Seeds[i]=seed;
                getpoint+=givepoint;
            }
            else{
                getpoint+=givepoint;
                Seeds[i]=seed;
            }
        }else{
            Seeds[i]=seed;
            getpoint+=givepoint;
        }
    }

    /*
    vector<vector<int>> dp(N+5,vector<int>(3,0));

    rep(i,N){
        if(T[i]=='r')seed=0,givepoint=P;
        else if(T[i]=='s')seed=1,givepoint=R;
        else seed=2,givepoint=S;
        rep(j,3){
            if(seed==j)getpoint=givepoint;
            else getpoint=0;
            if(i>K){
                dp[i+1][j]=max(dp[i-K][(j+1)%3],dp[i-K][(j+2)%3]);
            }else dp[i+1][j]=getpoint+dp[i][j];
        }
    }

    cout<<max(dp[N][0],max(dp[N][1],dp[N][2]))<<endl;
    */
    cout<<getpoint<<endl;

    return 0;
}

//rrrrrrrrr
//0     6
// 0     6
//  0     6
//   0     x
//    0     x
//     0     x
/*
    9 4 1 1 9 

*/

//a=97,z=122