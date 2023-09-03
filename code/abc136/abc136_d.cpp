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


int main(){
    string S;
    cin>>S;
    int N=S.size();
    //累積和的？
    vector<int> cs(N+2,0),ANS(N,0);
    REP(i,1,N+1){
        if(S[i-1]=='R')cs[i]=cs[i-1]+1;
    }
    for(int i=N;i>0;i--){
        if(S[i-1]=='L'){
            cs[i]=cs[i+1]-1;
            if(i!=N&&S[i]=='R')cs[i]=-1;
        }
    }
    //for(auto x:cs)cout<<x<<" ";
    //cout<<endl;
    //偶数回の移動が鍵
    bool t=true;
    REP(i,1,N+1){
        if(cs[i]<0){
            if(t){
                int a=cs[i-1]/2+cs[i-1]%2+(-cs[i])/2;
                int b=cs[i-1]/2+(-cs[i])/2+(-cs[i])%2;
                ANS[i-2]=a,ANS[i-1]=b;
                //cout<<i<<" "<<a<<" "<<b<<endl;
            }
            t=false;
        }else t=true;
    }
    for(auto x:ANS)cout<<x<<" ";
    cout<<endl;
    return 0;
}

//a=97,z=122
/*
RRRL
1110
0111
0021
RRL
110
011
011

*/