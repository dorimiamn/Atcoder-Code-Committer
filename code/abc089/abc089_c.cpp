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
    ll N;
    cin>>N;
    string MARCH="MARCH";
    vector<string> S(N);
    map<string,ll> mp;
    rep(i,N){
        cin>>S[i];
        mp[S[i].substr(0,1)]++;
    }

    ll ANS=0;
    ll A,B,C;

    rep(i,5){
        A=mp[MARCH.substr(i,1)];
        REP(j,i+1,5){
            B=mp[MARCH.substr(j,1)];
            REP(k,j+1,5){
                C=mp[MARCH.substr(k,1)];
                ANS+=(A*B*C);
            }
        }
    }
    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122