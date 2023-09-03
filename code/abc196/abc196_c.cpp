#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
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
    ll N;
    cin>>N;
    REP(i,1,1000001){
        if(stoll(to_string(i)+to_string(i))>N){
            cout<<i-1<<endl;
            return 0;
        }
    }
    return 0;
}
/*
repeatするだけ
数列を生成して、それを二分探索を用いて個数を求めていくのかな。
10^6までの数値を用いて数列を生成できそう
重複はsetで消せば良い？
普通にto_string使えば良いだけだった
to_stringゴリ押しでよく失敗したので使わないと思ったら普通に使うやつだった
stollとto_stringを使って文字列の繰り返しをしてそれを数値にしてるね
stoiのll verがstoll
*/