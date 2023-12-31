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
    int n;
    cin>>n;
    vector<string> s;
    if(n%2==1){
        cout<<endl;
        return 0;
    }
    for(int bit=0;bit<(1<<n);bit++){
        string t="";
        rep(i,n){
            if(bit&(1<<i))t+='(';
            else t+=')';
        }
        int cnt=0;
        bool ok=true;
        rep(i,n){
            if(t[i]=='(')cnt++;
            else cnt--;
            if(cnt<0)ok=false;
        }
        if(ok&&cnt==0)s.pb(t);
    }
    sort(ALL(s));
    for(auto x:s)cout<<x<<endl;
    return 0;
}
/*
外側から考えていけばいいんじゃないかな
そうなると再帰関数？
N<=20なのでbit全探索か……！
左括弧でプラス、右括弧でマイナスとするとその文字列が正しいかどうかの判定が可能なのか！
*/