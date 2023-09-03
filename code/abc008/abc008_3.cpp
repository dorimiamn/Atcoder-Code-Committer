/*
http://wk1080id.hatenablog.com/entry/2017/04/24/115643
勉強させていただいた記事
*/

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

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int N;
    cin>>N;
    vector<int>C(N);
    rep(i,N)cin>>C[i];
    double ev=0.0;

    rep(i,N){
        int s=0;
        rep(j,N)
            if(i!=j)s+=(C[i]%C[j]==0);
        if(s%2)ev+=0.5;//Cが表、Sが奇数、(S+1)/2通りある、C自身をSに含めて、いるから？
        else ev+=1.0*(s+2)/(2*s+2);
        //Sが偶数、S/2+1通り、これもCをSに含めているため。
        //コインを置く場所の通りはS+1通りある。+1するのはCの場所にコインを置くことも考慮？
        //1.0を付けないとint型で計算されて、丸め込まれてしまう。
    }

    cout<<decimal(8)<<ev<<endl;

    return 0;
}

//a=97,z=122