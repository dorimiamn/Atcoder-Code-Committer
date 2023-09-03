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
    int N;
    cin>>N;
    vector<vector<int>> sub(N+1);
    vector<int> P(N+1),maxP(N+1,0),minP(N+1,INF);
    REP(i,2,N+1){
        int A;
        cin>>A;
        sub[A].pb(i);
    }
    for(int i=N;i>0;i--){
        if(sub[i].size()==0){P[i]=1;continue;}
        for(int j:sub[i]){
            maxP[i]=max(maxP[i],P[j]);
            minP[i]=min(minP[i],P[j]);
        }
        P[i]=maxP[i]+minP[i]+1;
    }

    cout<<P[1]<<endl;
    
    return 0;
}

//a=97,z=122