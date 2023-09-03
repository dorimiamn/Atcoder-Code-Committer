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

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

using Graph=vii;

int main(){
    int N,X,Y;
    cin>>N>>X>>Y;
    X--,Y--;
    Graph G(N);
    REP(i,1,N){
        G[i].pb(i-1);
        G[i-1].pb(i);
    }
    G[X].pb(Y);
    G[Y].pb(X);
    map<int,int> mp;
    rep(i,N){
        queue<pair<int,int>> que;
        vi dist(N,INF);
        vector<bool> c(N,false);
        que.push({i,0});
        while(!que.empty()){
            int x=que.front().first;
            int d=que.front().second+1;
            que.pop();

            for(auto y:G[x]){
                if(dist[y]<d)continue;
                if(c[y])continue;
                if(y<=i)mp[d]--;
                dist[y]=d;
                c[y]=true;
                que.push({y,d});
            }
        }
        rep(j,N){
            if(dist[j]==INF)continue;
            mp[dist[j]]++;
            //cout<<j<<":"<<dist[j]<<" ";
        }
        //cout<<endl;
        //cout<<"i:"<<i<<endl;
    }
    //REP(i,1,N)cout<<mp[i]<<endl;
    REP(i,1,N)cout<<mp[i]<<endl;
    return 0;
}

//a=97,z=122