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
    int a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    if(a==1){
        if(b==2||b==3)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else if(a==2){
        if(b==4||b==5)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else if(a==3){
        if(b==6||b==7)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else if(a==4){
        if(b==8||b==9)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else if(a==5){
        if(b==10||b==11)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else if(a==6){
        if(b==12||b==13)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else if(a==7){
        if(b==14||b==15)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
/*

*/