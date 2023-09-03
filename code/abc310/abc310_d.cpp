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

int N,T,M;
// int ans=0;

set<vii>dist;
set<vii>ans;

void dfs(vector<set<int>>&st,vii &team,int cnt){

    // cout<<"cnt:"<<cnt<<endl;

    if(cnt>=N){
        rep(i,T){
            // cout<<team.at(i).size()<<endl;
            if(!team.at(i).size()){
                return ;
            }
        }
        sort(ALL(team));
        ans.insert(team);
        return ;
    }
    
    rep(i,T){
        bool ok=true;
        for(auto x:team.at(i)){
            //segfault
            // cout<<x<<endl;
             if(st[x].find(cnt)!=st[x].end()){
                ok=false;
                break;
            }
        }
        if(!ok)continue;
        vii newTeam=team;
        newTeam[i].pb(cnt);
        sort(ALL(newTeam));
        if(dist.find(newTeam)!=dist.end())continue;
        dist.insert(newTeam);
        dfs(st,newTeam,cnt+1);
    }
}

int main(){
    cin>>N>>T>>M;
    vector<set<int>> st(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        st[a].insert(b);
        st[b].insert(a);
    }

    vii team(T);

    dfs(st,team,0);

    // for(auto x:ans){
    //     for(auto y:x){
    //         for(auto z:y)cout<<z<<" ";
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    cout<<ans.size()<<endl;
    
    return 0;
}
/*
bit 全探索
set で中悪い人を管理
T個のチームに分けるのでbit 全探索ではなさそう
T進数と考えると楽？
dfs でチーム分けをして解けるんじゃないか？
*/