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
    ll X;
    cin>>X;

    vector<ll> arr;

    string S=to_string(X);

    rep(i,10){
        REP(j,-9,10){
            ll num=i,state=i+j;
            bool ok=true;
            rep(k,S.length()-1){
                if(state>10||state<0){
                    ok=false;
                    break;
                }
                num=num*10+state;
                state+=j;
            }
            if(ok)arr.pb(num);
        }
    }

    sort(ALL(arr));

    // for(auto y:arr)cout<<y<<endl;

    cout<<*lower_bound(ALL(arr),X)<<endl;

    return 0;
}
/*
DPであり得る数を全列挙
その後X以上で最小な等差数を二分探索で見つける。
空間が広すぎるので全列挙は難しいのでは？
探索する空間を如何に小さくするかを考えれば良い？
priority_queueを使って既存の数から新しい数列を生成？
でも等差を保証できないか
大きな数で等差数を考えてみよう。

Sample3 8989898989
この場合、これを満たすようなAnswerは
9876543210
である。等差数なのだからこれは当然。求められる数は大きく限られる。だから、空間は足りる！
10^10以降だと、交差は0になるのでは？
桁が与えられたXと異なることはない！なぜなら、桁上がり前に9が連続する数があり、これが交差数であるから、必ず同じ桁の中で解がもとまる。
*/