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
    int N,M;
    cin>>N>>M;
    vector<vector<int>> Graph(N,vector<int>());
    vector<int> memo(N,-1);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        Graph[a].pb(b);
        Graph[b].pb(a);
    }
    queue<int> que;
    vector<bool> dist(N,false);
    que.push(0);
    while(!que.empty()){
        int a=que.front();
        que.pop();
        for(auto x:Graph[a]){
            if(dist[x])continue;
            dist[x]=true;
            memo[x]=a;
            que.push(x);
        }
    }
    REP(i,1,N){
        if(memo[i]==-1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    REP(i,1,N)cout<<memo[i]+1<<endl;
    return 0;
}

//a=97,z=122