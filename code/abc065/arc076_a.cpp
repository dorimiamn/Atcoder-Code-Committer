#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()


int main(){
    int N,M;
    bool t=false;
    cin>>N>>M;
    if(abs(N-M)>1){
        cout<<0<<endl;
        return 0;
    }else if(abs(N-M)==1)t=true;
    ll A=1,B=1;
    REP(i,2,N+1){
        A*=i;
        A%=INF;
    }
    REP(i,2,M+1){
        B*=i;
        B%=INF;
    }
    ll ANS;
    if(t)ANS=A*B%INF;
    else ANS=A*B%INF*2%INF;

    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122