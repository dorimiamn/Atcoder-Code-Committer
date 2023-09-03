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
    cin>>N>>M;
    vector<vector<int>> X(N);
    vector<int> cnts(N,0);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        X[a].pb(b);
        X[b].pb(a);
    }

    rep(i,N){
        //サイクルとなっていない関係を探す
        int cnt=0;
        queue<pair<int,int>> que;
        que.push(make_pair(i,0));
        bool dist[11]={false};
        dist[i]=true;

        while(!que.empty()){
            int x=que.front().first;
            int times=que.front().second;
            que.pop();
            if(times==2){
                bool ok=true;
                for(auto y:X[x]){
                    if(y==i)ok=false;
                }
                if(ok)cnt++;
            }else{
                for(auto y:X[x]){
                    if(dist[y])continue;
                    dist[y]=true;
                    que.push(make_pair(y,times+1));
                }
            }
        }
        cnts[i]=cnt;
    }

    rep(i,N)cout<<cnts[i]<<endl;

    return 0;
}

//a=97,z=122