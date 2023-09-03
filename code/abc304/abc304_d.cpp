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
    int W,H,N;
    cin>>W>>H>>N;
    vector<pair<int,int>> points(N);
    rep(i,N){
        int x,y;
        cin>>x>>y;
        points[i]={x,y};
    }

    ll A,B;
    cin>>A;
    vi a(A+1,0);
    rep(i,A){
        cin>>a[i+1];
    }
    cin>>B;
    vi b(B+1,0);
    rep(i,B){
        cin>>b[i+1];
    }

    map<pair<int,int>,int>mp;

    rep(i,N){
        auto [x,y]=points[i];
        int p=lower_bound(ALL(a),x)-a.begin(),q=lower_bound(ALL(b),y)-b.begin();
        mp[{p,q}]++;
    }

    int mans=INF,Mans=0;

    if((A+1)*(B+1)>(ll)mp.size())mans=0;

    for(auto [key,value]:mp){
        // cout<<key.first<<" "<<key.second<<" "<<value<<endl;
        chmin(mans,value);
        chmax(Mans,value);
    }

    cout<<mans<<" "<<Mans<<endl;

    return 0;
}
/*
二分探索でいけないか？
各点を分類する。
苺の数だけしかエリアは使われない。
*/