#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
const int INF=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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
    int N,M,H,K;
    string S;
    cin>>N>>M>>H>>K>>S;

    map<pair<int,int>,bool> mp;

    rep(i,M){
        int x,y;
        cin>>x>>y;
        mp[{x,y}]=true;
    }

    bool ok=true;
    int tx=0,ty=0;

    rep(i,N){
        H--;
        if(H<0){
            ok=false;
            break;
        }
        if(S[i]=='R')tx++;
        if(S[i]=='L')tx--;
        if(S[i]=='U')ty++;
        if(S[i]=='D')ty--;
        if(mp[{tx,ty}]&&H<K){
            mp[{tx,ty}]=false;
            H=K;
        }
    }

    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
/*
pairを素集合で管理？
ありうるペアの総数をそこから引く
*/