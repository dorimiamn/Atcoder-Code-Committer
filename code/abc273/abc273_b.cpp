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
    int K;
    string X;
    cin>>X>>K;
    rep(i,K){
        if(X.size()<i+1)break;
        string str="";
        rep(j,i+1){
            str=X[X.size()-j-1]+str;
        }
        ll a=stol(str);
        ll key=pow(10,i+1);
        // cout<<a<<endl;
        if(a<key/2){
            rep(j,i+1)X[X.size()-j-1]='0';
            // cout<<"kiri:"<<X<<endl;
        }else{
            rep(j,i+1)X[X.size()-j-1]='0';
            bool check=true;
            // cout<<X<<endl;
            REP(j,i+1,X.size()){
                if(X[X.size()-j-1]!='9'){
                    X[X.size()-j-1]=char(X[X.size()-j-1]+1);
                    check=false;
                    break;
                }
                X[X.size()-j-1]='0';
            }
            if(check){
                X='1'+X;
            }
            // cout<<X<<endl;
        }
    }
    ll ans=stol(X);
    cout<<ans<<endl;
    return 0;
}
/*

*/