/*
http://wk1080id.hatenablog.com/entry/2017/02/16/233348
勉強させていただいた記事
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll LongINF=1e18+7;
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

//解説AC.......
//ちゃんと記事は読まねば……

int main(){
    ll N,H,A,B,C,D,E;
    cin>>N>>H>>A>>B>>C>>D>>E;

    ll ANS=LongINF;

    rep(X,N+1){
        if(H+(B+E)*X-E*N>0){//普通の食事をi日、食べない日をN-Xとして、それの満腹度が0より大きければ質素な食事は必要ないため
            ANS=min(ANS,ll(X*A));
        }else{
            ll Y=((N-X)*E-H-B*X)/(D+E)+1;
            if(X+Y<=N)
                ANS=min(ANS,ll(X*A+Y*C));
        }
    }

    cout<<ANS<<endl;
    return 0;
}

//a=97,z=122