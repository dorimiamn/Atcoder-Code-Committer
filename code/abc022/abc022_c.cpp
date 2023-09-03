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
    vector<vector<int>> d(310,vector<int>(310,INF));
    vector<pair<int,pair<int,int>>> p;

    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;//0-indexを忘れるな!
        if(a==0||b==0){
            if(b==0)swap(a,b);
            p.pb(make_pair(c,make_pair(a,b)));
            continue;
        }
        d[a][b]=c;
        d[b][a]=c;
    }

    rep(k,N){
        rep(i,N){
            rep(j,N){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int o=p.size();
    int ANS=INF;
    rep(i,o){
        rep(j,o){
            if(i==j)continue;
            int sum,fu=p[i].second.second,lv=p[j].second.second;
            sum=p[i].first+p[j].first;
            ANS=min(ANS,sum+d[fu][lv]);
            ANS=min(ANS,sum+d[lv][fu]);
        }
    }
    if(ANS==INF)cout<<-1<<endl;
    else cout<<ANS<<endl;

    return 0;
}

//a=97,z=122