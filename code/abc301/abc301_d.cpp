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
    ll N;
    string S;
    cin>>S>>N;
    //反転させて上位bitから見れるように
    reverse(S.begin(),S.end());
    while(S.size()<60)S.pb('0');
    //s[i]が'?'でないかつS[i]がnのi bit目と異なる最上位bitの位置
    int lb=-1;
    rep(i,60){
        if(S[i]!='?'&&S[i]-'0' != (N >> i & 1))lb=i;
    }
    if(lb==-1){
        //Nと異なるbitがないとき
        cout<<N<<endl;
        return 0;
    }
    //上位bitから下位bitへと貪欲に処理。
    REP(i,lb,60){
        //s[?]の場合でもcontinueされるけど大丈夫なのか？と思ったら後でカバーされてた。
        if(S[i]=='1'||!(N>>i&1))continue;
        S[i]='0';
        //下位bitの'?'は1で埋める
        rep(j,i){
            if(S[j]=='?')S[j]='1';
        }
        //上位bitの場合はn[j]で置換
        REP(j,i+1,60){
            S[j]='0'+(N>>j&1);
        }
        //10進数変換
        ll ans=0;
        for(int j=59;j>=0;j--){
            ans*=2;
            ans+=S[j]-'0';
        }
        cout<<ans<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}
/*
二分探索で最大値?
*/