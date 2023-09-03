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

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int D,N=0,ans=INF;
    double W;
    cin>>D>>W;
    //int C[]={113,338,563,789,1013,1238,1463,1688,1913,2138,2363,2588,2813,3038,3263};
    string ANS[]={"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","C"};
    for(int i=113;i<=3488;i+=225,N++){
        if(D<i)break;
    }
    if(N==16)N=0;
    W/=60;
    W=round(W*10);
    //cout<<W<<endl;
    int c[]={0,3,16,34,55,80,108,139,172,208,245,285,327};
    for(int i=12;i>=0;i--){
        if(c[i]<=W){
            ans=i;
            break;
        }
    }
    if(ans==INF)ans=12;
    if(ans==0)N=16;

    cout<<ANS[N]<<" "<<ans<<endl;

    return 0;
}

//a=97,z=122
