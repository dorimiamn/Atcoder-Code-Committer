/*
解説AC
拝読した解説
https://drken1215.hatenablog.com/entry/2020/11/22/224600
原点を基準にする。
初期(a,b)目標(x,y)
目標座標は{abs(x-a),abs(y-b)}となる
試すとわかるけれども、斜め方向への移動は無限にできると考えていい。
*/
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
    int x,y,w,z;
    cin>>x>>y>>w>>z;
    int p=abs(w-x),q=abs(z-y);
    if(p==q&&q==0){
        cout<<0<<endl;
    }else if(p==q||p+q<=3){
        cout<<1<<endl;
    }else{
        if((p+q)%2==0||p+q<=6||abs(p-q)<=3){
            cout<<2<<endl;
        }else{
            cout<<3<<endl;
        }
    }
    return 0;
}

//a=97,z=122