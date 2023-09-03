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
    int h,w,k,ans=0;
    cin>>h>>w>>k;
    vector<string> s(h);
    rep(i,h)cin>>s[i];
    for(int bit1=0;bit1<(1<<h);++bit1){
        for(int bit2=0;bit2<(1<<w);++bit2){
            vector<string> l=s;
            rep(i,h){
                if(bit1&(1<<i)){
                    rep(j,w){
                        l[i][j]='.';
                    }
                }
            }
            rep(i,w){
                if(bit2&(1<<i)){
                    rep(j,h){
                        l[j][i]='.';
                    }
                }
            }
            int cnt=0;
            rep(i,h){
                rep(j,w){
                    if(l[i][j]=='#')cnt++;
                }
            }
            if(cnt==k)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122