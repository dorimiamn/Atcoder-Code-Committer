#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
const int INF=1000000007;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int N;
    cin>>N;
    vector<string> s(N);
    rep(i,N){
        cin>>s[i];
    }
    vi b;
    b.pb(s[0][0]-'0');
    int x=0,y=0,dir=0;
    while(1){
        // cout<<x<<" "<<y<<endl;
        int nx=x+dx[dir],ny=y+dy[dir];
        if(nx<0||N<=nx||ny<0||N<=ny){
            dir++;
        }
        nx=x+dx[dir],ny=y+dy[dir];
        if(nx==0&&ny==0)break;
        b.pb(s[ny][nx]-'0');
        x=nx,y=ny;
    }
    int cnt=1;
    x=y=dir=0;
    s[0][0]=char(b.back()+'0');
    while(1){
        // cout<<x<<" "<<y<<endl;
        int nx=x+dx[dir],ny=y+dy[dir];
        if(nx<0||N<=nx||ny<0||N<=ny){
            dir++;
        }
        nx=x+dx[dir],ny=y+dy[dir];
        if(nx==0&&ny==0)break;
        // cout<<ny<<" "<<nx<<" "<<char(b[(b.size()-1+cnt)%b.size()]+'0')<<endl;
        s[ny][nx]=char(b[(b.size()-1+cnt)%b.size()]+'0');
        x=nx,y=ny;
        cnt++;
    }

    // for(auto io:b)cout<<io<<endl;
    rep(i,N)cout<<s[i]<<endl;
    return 0;
}
/*

*/