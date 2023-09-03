#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
const int INF=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    ll X,Y,Z;
    string S;
    cin>>X>>Y>>Z>>S;

    ll ans=LongINF,N=S.length(),sum=0;

    vi press;
    bool isA=true;
    rep(i,N){
        if(isA&&S[i]=='A'){
            press.pb(sum);
            isA=false;
            sum=1;
        }else if(!isA&&S[i]=='a'){
            press.pb(sum);
            isA=true;
            sum=1;
        }else if(S[i]=='a'){
            sum++;
        }else if(S[i]=='A'){
            sum++;
        }
    }
    press.pb(sum);

    vii dp(press.size()+5,vi(3,0));
    dp[0][1]=Z;

    // cout<<"press"<<press.size()<<endl;

    rep(i,press.size()){
        if(i%2){
            dp[i+1][0]=min(dp[i][0]+Y*press[i],dp[i][1]+Z+Y*press[i]);
            dp[i+1][1]=min(X*press[i]+Z+dp[i][0],X*press[i]+dp[i][1]);
        }else{
            dp[i+1][0]=min(dp[i][0]+X*press[i],dp[i][1]+Z+X*press[i]);
            dp[i+1][1]=min(dp[i][0]+Z+Y*press[i],dp[i][1]+Y*press[i]);
        }
        // cout<<dp[i+1][0]<<" "<<dp[i+1][1]<<endl;
    }


    // for(auto ax:press)cout<<ax<<" ";
    // cout<<endl;

    rep(i,2){
        // cout<<dp[press.size()][i]<<endl;
        chmin(ans,dp[press.size()][i]);
        // cout<<"ans:"<<ans<<endl;
    }

    cout<<ans<<endl;

    return 0;
}
/*
圧縮できそう。
圧縮して、それらをどう押すのが良いかを足し合わせてく？
DP????
aだけを押す遷移には、aだけを押すときとCapsを押し直した時がある？
0:Capsなし
1:Capsあり

A:
    dp[i+1][0]=(dp[i][0]+Y),(dp[i][1]+Z+Y),
    dp[i+1][1]=(dp[i][0]+Z+X),(dp[i][1]+X),
a:
    dp[i+1][0]=(dp[i][0]+X),(dp[i][1]+Z+X)


*/