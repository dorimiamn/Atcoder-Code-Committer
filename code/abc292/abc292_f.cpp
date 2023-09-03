//解説Submit
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

ld A,B;

bool check1(ld),check2(ld,ld);

bool check1(ld length){
    ld ok=M_PI/6,ng=0;
    rep(_,200){
        ld md=(ok+ng)/2;
        if(check2(md,length))ok=md;
        else ng=md;
        // cout<<ok<<" "<<ng<<endl;
    }
    // cout<<"check:"<<decimal(6)<<ok<<endl;
    if(length*cos(M_PI/6-ok)<=B)return true;
    else return false;
}

bool check2(ld theta,ld length){
    if(length*cos(theta)<=A)return true;
    else return false;
}

int main(){
    cin>>A>>B;

    if(A<B)swap(A,B);

    ld ok=0,ng=1e6;
    rep(_,200){
        ld md=(ok+ng)/2;
        if(check1(md))ok=md;
        else ng=md;
        // cout<<decimal(8)<<ok<<" "<<ng<<endl;
    }

    cout<<decimal(20)<<ok<<endl;

    return 0;
}
/*
図を書いてみると
三角形の一片の長さを l として
lcos(theta)<A & lcos(pi/6 - theta)<B
をみたすひつようがある。 
l について二分探索し、その判定関数の中で、Thetaについて二分探索をおこなって条件を満たしているかを判定する。
*/