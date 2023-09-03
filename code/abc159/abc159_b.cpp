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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

bool solve(string S){
    int n=S.size();
    if(n%2==1){
        string x;
        rep(i,n/2)x.pb(S[i]);
        string y;
        REP(i,n/2+1,n)y.pb(S[i]);
        reverse(ALL(y));
        if(x==y)return true;
        return false;
    }else{
        string x,y;
        rep(i,n/2)x.pb(S[i]);
        REP(i,n/2,n)y.pb(S[i]);
        reverse(ALL(y));
        if(x==y)return true;
        return false;
    }
}

int main(){
    string S;
    cin>>S;
    if(!solve(S)){
        cout<<"No"<<endl;
        return 0;
    }
    int N=S.size();
    string a;
    rep(i,(N-1)/2){
        a+=S[i];
    }
    if(!solve(a)){
        cout<<"No"<<endl;
        return 0;
    }
    //cout<<a<<endl;
    a="";
    REP(i,(N+3)/2-1,N){
        a+=S[i];
    }
    if(!solve(a)){
        cout<<"No"<<endl;
        return 0;
    }
    //cout<<a<<endl;
    cout<<"Yes"<<endl;
    return 0;
}

//a=97,z=122