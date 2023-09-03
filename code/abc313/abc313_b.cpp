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
    int N,M;
    cin>>N>>M;
    vii graph(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        graph[b-1].pb(a-1);
    }

    vector<bool> dist(N);
    int ans=-1;

    rep(i,N){
        if(dist[i])continue;
        dist[i]=true;
        queue<int> que;
        que.push(i);
        // cout<<i<<" "<<ans<<endl;
        while(!que.empty()){
            int x=que.front();
            dist[x]=true;
            que.pop();
            if(!graph[x].size()){
                if(ans!=x+1&&ans!=-1){
                    ans=-1;
                    i=N;
                    break;
                }
                ans=x+1;
                break;
            }
            for(auto y:graph[x]){
                que.push(y);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
/*

*/