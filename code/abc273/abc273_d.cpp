//解説Submit
//連想配列を用いて壁の位置を管理。行動時に当たる壁の位置も二分探索を用いて求めることが可能！実装重めで復習したい問題。

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

//列、行の壁を連想配列で管理
map<int,vi> amp,bmp;

int main(){
    int H,W,r,c,N,Q;
    cin>>H>>W>>r>>c>>N;
    REP(i,1,N+1){
        int rr,cc;
        cin>>rr>>cc;
        amp[rr].push_back(cc),bmp[cc].push_back(rr);
    }
    //行の中で壁のある列の場所をsort,bmpも同様
    for(auto &p:amp)sort(ALL(p.second));
    for(auto &p:bmp)sort(ALL(p.second));

    cin>>Q;
    char d;
    int l;
    rep(_,Q){
        cin>>d>>l;
        if(d=='L'){
            auto it=amp.find(r);int lb=0;
            if(it!=amp.end()){
                vi &vec=it->second;
                auto it2=lower_bound(ALL(vec),c);
                if(it2!=vec.begin())it2--,lb=*it2;
            }
            c=max(c-l,lb+1);
        }
        if(d=='U'){
            auto it=bmp.find(c);int lb=0;
            if(it!=bmp.end()){
                vi &vec=it->second;
                auto it2=lower_bound(ALL(vec),r);
                if(it2!=vec.begin())it2--,lb=*it2;
            }
            r=max(r-l,lb+1);
        }
        if(d=='R'){
            auto it=amp.find(r);int ub=W+1;
            if(it!=amp.end()){
                vi &vec=it->second;
                auto it2=upper_bound(ALL(vec),c);
                if(it2!=vec.end())ub=*it2;
            }
            c=min(c+l,ub-1);
        }
        if(d=='D'){
            auto it=bmp.find(c);int ub=H+1;
            if(it!=bmp.end()){
                vi &vec=it->second;
                auto it2=upper_bound(ALL(vec),r);
                if(it2!=vec.end())ub=*it2;
            }
            r=min(r+l,ub-1);
        }
        cout<<r<<" "<<c<<endl;
    }

    return 0;
}
/*

*/