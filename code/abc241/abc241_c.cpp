#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1,1,1,-1,-1};
const int dy[]={1,0,-1,0,1,-1,1,-1};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
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
    int n;
    cin>>n;
    vector<string> s(n);
    rep(i,n)cin>>s[i];
    bool ans=false;
    rep(i,n){
        rep(j,n){
            rep(k,8){
                int x=i,y=j,limit=2,cnt=0;
                if(s[y][x]=='.')limit--,cnt++;
                else cnt++;
                rep(l,5){
                    x+=dx[k],y+=dy[k];
                    if(x>=n||x<0||y>=n||y<0)break;
                    //cout<<x<<" "<<y<<endl;
                    if(s[y][x]=='.'){
                        limit--,cnt++;
                    }else cnt++;
                }
                if(cnt==6&&limit>=0){
                    //cout<<x<<" "<<y<<" "<<k<<endl;
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
/*
ななめを忘れてる
以下を追加
dx=[1,1,-1,-1]
dy=[1,-1,1,-1]
*/