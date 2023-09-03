#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
const int INF=1000000007;
const int dx[]={0,1,0,-1,1,1,-1,-1};
const int dy[]={1,0,-1,0,1,-1,1,-1};

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

string snuke="snuke";

int main(){
    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    rep(i,H)cin>>S[i];

    rep(i,H){
        rep(j,W){
            bool ok1=false;
            vector<pair<int,int>> ans;
            if(S[i][j]==snuke[0]){
                
                // cout<<"a"<<i<<" "<<j<<endl;

                rep(k,8){
                    bool ok2=true;
                    int y=i,x=j;
                    vector<pair<int,int>>point;
                    point.pb({y,x});
                    REP(l,1,5){
                        y+=dy[k],x+=dx[k];
                        // cout<<y<<" "<<x<<endl;
                        if(y<0||H<=y||x<0||W<=x)continue;
                        if(S[y][x]==snuke[l]){
                            point.pb({y,x});
                        }else{
                            ok2=false;
                            break;
                        }
                    }

                    if(ok2&&point.size()==5){
                        ans=point;
                        break;
                    }
                    
                    // cout<<endl;
                }
                if(ans.size()==5){
                    for(auto [y,x]:ans)cout<<y+1<<" "<<x+1<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
/*

*/