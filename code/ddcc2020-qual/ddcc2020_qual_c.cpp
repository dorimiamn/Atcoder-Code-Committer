/*
https://scrapbox.io/ganariya/AtCoderDISCO2020_C%E5%95%8F%E9%A1%8C400%E7%82%B9_%E3%80%8CStrawberry_Cakes%E3%80%8D
勉強させて頂いた解説
横で塗り分けて、それを上下に広めていくという、次元を固定した考え方？
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
    int h,w,k,cnt=1;
    vector<int> strawbery(309,0);
    vii ans(309,vi(309,0));
    char s[309][309];
    cin>>h>>w>>k;
    rep(i,h){
        rep(j,w){
            cin>>s[i][j];
            //横に区切り、あるかどうかcnt
            if(s[i][j]=='#')strawbery[i]++;
        }
    }
    rep(i,h){
        if(strawbery[i]>0){
            rep(j,w){
                ans[i][j]=cnt;
                if(s[i][j]=='#'){
                    strawbery[i]--;
                    if(strawbery[i]>0)cnt++;
                }
                //cout<<"i:"<<i<<"="<<strawbery[i]<<endl;
            }
            cnt++;
        }
    }
    //上から塗るだけでは塗り残しができてしまうので、
    //下からも塗る操作が必要
    /*
    4 4 1
    ....
    ....
    #...
    ....
    のケースで落ちる。
    */
    REP(i,1,h){
        if(ans[i][0]==0){
            rep(j,w){
                ans[i][j]=ans[i-1][j];
            }
        }
    }

    for(int i=h-2;i>=0;i--){
        if(ans[i][0]==0){
            rep(j,w){
                ans[i][j]=ans[i+1][j];
            }
        }
    }

    rep(i,h){
        rep(j,w){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

//a=97,z=122