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
    ll n,ans=0;
    vi cnt(3,0);
    cin>>n;
    vector<string> s(n);
    rep(i,n){
        cin>>s[i];
        rep(j,s[i].size()-1){
            if(s[i][j]=='A'&&s[i][j+1]=='B')ans++;
        }
        if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A')cnt[0]++;
        else if(s[i][0]=='B')cnt[1]++;
        else if(s[i][s[i].size()-1]=='A')cnt[2]++;
    }
    //cout<<ans<<endl;
    //cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
    if(cnt[2]!=0&&cnt[1]!=0){
        ans+=cnt[0]+1;
        cnt[1]--;
        cnt[2]--;
    }
    else if(cnt[1]!=0){
        ans+=cnt[0];
        cnt[1]--;
    }else if(cnt[2]!=0){
        ans+=cnt[0];
        cnt[2]--;
    }else{
        ans+=max(0,cnt[0]-1);
    }
    ans+=min(cnt[1],cnt[2]);
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122