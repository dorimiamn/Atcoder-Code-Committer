//https://outline.hatenadiary.jp/entry/2019/12/17/021530
//勉強させて頂いた記事

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

//記事から、XORは桁上がりのない加算！
//上記のことから、一つの桁だけを考えて処理すれば良いことがわかる
//他の桁に影響を及ぼさないため。
//d桁目で、0である数字の個数と、1である数字の個数の積に2**dを掛けたものの総和が解である。
//bit演算大切

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];

    ll res=0;
    rep(d,60){
        ll n0=0,n1=0;
        rep(i,N){
            if((A[i]>>d)&1)++n1;
            else ++n0;
        }
        ll tmp=(1LL<<d)%INF;//調べるbitの場所のフラグ

        ll n=n0*n1%INF;
        tmp=tmp*n%INF;
        res=(res+tmp)%INF;
    }

    cout<<res<<endl;


    return 0;
}

//a=97,z=122