#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1LL<<60;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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
    ll n,left=0,right=LongINF;
    cin>>n;
    vector<ll> h(n),s(n);
    rep(i,n){
        cin>>h[i]>>s[i];
    }
    while(right-left>1){
        ll half=(left+right)/2;
        bool isOk=true;
        vector<ll> a(n);
        rep(i,n){
            if(half<h[i])isOk=false;
            else a[i]=(half-h[i])/s[i];
        }
        sort(ALL(a));
        rep(i,n){
            if(a[i]<i){
                isOk=false;
                break;
            }
        }
        //for(auto x:a)cout<<x<<" ";
        //cout<<"right,half,left"<<right<<" "<<half<<" "<<left<<endl;
        if(isOk)right=half;
        else left=half;
    }
    cout<<right<<endl;
    return 0;
}
/*
1秒って割るんじゃなくて、0秒から風船を割ることができるよ！
解説Submit

https://drken1215.hatenablog.com/entry/2021/06/12/113100
実装がうまくいかないためけんちょん様の記事を見て自分の実装と比較
mid<h[i]の判定がうまくいっていなかった？違うみたい
十分大きい値が不十分ぽい……？
2^60>10^13
1en と表すよりbitで考えた方が最大値近くの値を出せそう
というか、問題文から十分大きい値を考えるべきだった。
*/