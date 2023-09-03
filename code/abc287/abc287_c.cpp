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
    int n,m;
    cin>>n>>m;
    vii graph(n);
    if(m==0){
        if(n==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi dist(n,0);
    int cnt=0,v=0;
    rep(i,n){
        if(graph[i].size()==1){
            cnt++;
            v=i;
        }
    }
    if(cnt!=2){
        cout<<"No"<<endl;
        return 0;
    }
    dist[v]=1;
    cnt=1;
    while(cnt<n){
        int nv;
        if(graph[v].size()>2){
            cout<<"No"<<endl;
            return 0;
        }else if(graph[v].size()==2){
            int a=0;
            rep(i,2){
                if(dist[graph[v][i]])a++;
                else nv=graph[v][i];
            }
            if(a==2){
                cout<<"No"<<endl;
                return 0;
            }
        }else{
            if(dist[graph[v][0]]){
                cout<<"No"<<endl;
                return 0;
            }else{
                nv=graph[v][0];
            }
        }
        v=nv;
        dist[v]=1;
        cnt++;
    }
    cout<<"Yes"<<endl;
    return 0;
}
/*

*/