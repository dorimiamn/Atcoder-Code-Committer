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
    ll Min=LongINF;
    int N,M,X;
    cin>>N>>M>>X;
    vi C(N);
    vector<vector<int>> book(N,vector<int>(M,0));
    rep(i,N){
        cin>>C[i];
        rep(j,M)cin>>book[i][j];
    }
    for(int bit=0;bit<(1<<N);bit++){
        ll money=0;
        vector<int> under(M,0);
        rep(i,N){
            if(bit&(1<<i)){
                money+=C[i];
                rep(j,M){
                    under[j]+=book[i][j];
                }
            }
        }
        int cnt=0;
        rep(i,M){
            if(under[i]>=X){
                cnt++;
            }
        }
        if(cnt>=M){
            //cout<<money<<endl;
            Min=min(Min,money);
        }
    }
    if(Min==LongINF)Min=-1;
    cout<<Min<<endl;
    return 0;
}

//a=97,z=122