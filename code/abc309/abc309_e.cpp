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
    vi p(N,0);
    vii graph(N);
    rep(i,N-1){
        cin>>p[i+1];
        p[i+1]--;
        graph[p[i+1]].pb(i+1);
    }

    vi x(M),y(M);
    vi ins(N,0);
    rep(i,M){
        cin>>x[i]>>y[i];
        x[i]--;
        chmax(ins[x[i]],y[i]);
    }


    vector<bool> isTarget(N,false);

    rep(i,N){
        if(isTarget[i])continue;
        if(!ins[i])continue;
        isTarget[i]=true;
        queue<pair<int,int>> que;
        que.push({i,ins[i]});
        while(que.size()){
            auto [person,cnt]=que.front();
            que.pop();

            for(auto newPerson:graph[person]){
                isTarget[newPerson]=true;
                if(!ins[newPerson]&&cnt-1==0)continue;
                que.push({newPerson,max(ins[newPerson],cnt-1)});
            }
        }
    }

    int ans=0;
    rep(i,N){
        if(isTarget[i]){
            ans++;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}
/*
有向なグラフを作って、上から見ていく。
そのときに、保険の回数を更新できそうならしておく。
*/