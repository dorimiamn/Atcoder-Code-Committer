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
    int now=0;
    string s;
    cin>>s;
    vii character(s.length(),vi(0));
    vector<bool> inBox(30,false);
    rep(i,s.length()){
        if(s[i]=='(')now++;
        else if(s[i]==')'){
            for(auto c:character[now]){
                inBox[c]=false;
            }
            character[now].clear();
            now--;
        }else{
            if(inBox[(s[i]-'a')]){
                cout<<"No"<<endl;
                return 0;
            }
            inBox[(s[i]-'a')]=true;
            character[now].pb(s[i]-'a');
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
/*
alphabetは、何番目の操作で入れたか、または入っていないかの状態を表す。
cnt1とcnt2の対応関係を間違えていた！
(a(a)(a))
のときに対応関係を見つけられていないのでは？
*/