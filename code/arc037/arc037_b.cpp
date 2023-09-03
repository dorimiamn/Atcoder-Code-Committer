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

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)


int main(){
    int N,M;
    cin>>N>>M;

    vii G(N);
    rep(i,M){
        int u,v;
        cin>>u>>v;
        u--,v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<bool>dist(N,false);
    int cnt=0;

    rep(i,N){
        if(dist[i])continue;

        //cout<<"root:"<<i<<endl;

        bool ok=true;
        queue<pair<int,int>> que;
        for(auto x:G[i]){
            que.push(make_pair(x,i));
            dist[x]=true;
        }
        while(!que.empty()){
            int x=que.front().first,y=que.front().second;
            //cout<<x<<endl;
            que.pop();
            for(auto z:G[x]){
                if(z==y)continue;
                if(dist[z]){
                    ok=false;
                    dist[z]=true;
                    break;
                }
                que.push(make_pair(z,x));
                //cout<<"dist:"<<z<<endl;
                dist[z]=true;
            }
            if(!ok)break;
        }
        //cout<<endl;
        if(ok)cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}

//a=97,z=122