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
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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
    int N,Q,ans;
    cin>>N>>Q;
    vector<set<int>> st(N);
    ans=N;
    rep(q,Q){
        int i;
        cin>>i;
        if(i==1){
            int u,v;
            cin>>u>>v;
            u--,v--;
            if(st[u].empty())ans--;
            if(st[v].empty())ans--;
            st[u].insert(v);
            st[v].insert(u);
            cout<<ans<<endl;
        }else{
            int v;
            cin>>v;
            v--;
            for(auto x:st[v]){
                if(st[x].empty())continue;
                st[x].erase(v);
                if(st[x].empty())ans++;
            }
            if(st[v].empty()){
                cout<<ans<<endl;
            }else{
                st[v].clear();
                ans++;
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
/*

*/