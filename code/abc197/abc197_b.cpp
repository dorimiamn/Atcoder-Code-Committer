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
    int H,W,X,Y,cnt=1;
    cin>>H>>W>>X>>Y;
    vector<string> S(H);
    rep(i,H)cin>>S[i];
    rep(i,4){
        int x=X-1,y=Y-1;
        while(S[x][y]=='.'){
            y+=dy[i],x+=dx[i];
            if(y<0||W-1<y||x<0||H-1<x)break;
            if(S[x][y]=='#')break;
            cnt++;
            //cout<<i<<" "<<y<<" "<<x<<endl;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
/*
HとWの関係が逆だった……
*/