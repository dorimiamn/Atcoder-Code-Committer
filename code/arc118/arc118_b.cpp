/*
解説Submit
勉強させていただいた記事
https://scrapbox.io/Example0911/ARC118_B_Village_of_M_People
*/

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

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int K,N,M;
    cin>>K>>N>>M;
    vector<ll> A(K);
    rep(i,K)cin>>A[i];
    ll ok=LongINF,ng=-1;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        ll L=0,R=0;
        rep(i,K){
            L+=(M*A[i]-mid+N-1)/N;
            R+=(M*A[i]+mid)/N;
        }
        //常にLとRの総和はMを挟む。
        if(L<=M&&M<=R)ok=mid;
        else ng=mid;
    }
    //こうすることで、総和がMであるような数列がもとまる条件式の最小値が求まる。

    //数列の構築
    //一旦LでBを計算。その後余った部分をRまで詰めるようにしてBを求めてく
    ll sum=0;
    vector<ll> B(K),r(K);
    rep(i,K){
        //上の二分探索のrを流用すると、最後がngで終わった時の配列を使ってしまって、答えが正しく得られない。
        r[i]=(M*A[i]+ok)/N;
        B[i]=(M*A[i]-ok+N-1)/N;
        sum+=B[i];
    }

    rep(i,K){
        int x=min(M-sum,r[i]-B[i]);
        B[i]+=x;
        sum+=x;
        // cout<<sum<<" "<<x<<" "<<r[i]<<" "<<B[i]<<endl;
    }

    for(auto x:B)cout<<x<<endl;

    return 0;
}
/*
二分探索はわかったんだけど、数列を構築するのはどうしたら良いかわからなかった。
数列の総和=Mを満たすにはどうしたら良いかって部分で引っかかり

最後らへん貪欲な部分(Bの構築を詰めれるだけ詰めていくところ)があって、これでどうしていいのか悩んだけど、
判定値の最小値を求めるときに左側と右側の総和を求めてるよね。この右側の総和よりも下にM=Bの総和があるわけだから、
この条件さえ守れば貪欲をしても良い。詰めれるだけ詰めると判定値が最小に近づいていくということ。だから貪欲見たくなってる。

切り上げは (a+M-1)/Mって形でできるよね
*/