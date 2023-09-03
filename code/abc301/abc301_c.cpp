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

string AtCoder="atcoder";

int main(){
    string S,T;
    cin>>S>>T;
    int N=S.length();
    vii cards(2,vi(30,0));
    rep(i,N){
        if(S[i]=='@')cards[0][26]++;
        else cards[0][int(S[i]-'a')]++;
    }
    rep(i,N){
        if(T[i]=='@')cards[1][26]++;
        else cards[1][int(T[i]-'a')]++;
    }

    int debugnum=26;

    // cout<<cards[0][debugnum]<<" "<<cards[1][debugnum]<<endl;

    rep(i,26){
        int delta=min(cards[0][i],cards[1][i]);
        cards[0][i]-=delta,cards[1][i]-=delta;
    }

    // cout<<cards[0][debugnum]<<" "<<cards[1][debugnum]<<endl;

    rep(i,26){
        if(cards[0][i]||cards[1][i]){
            bool ok=false;
            rep(j,7){
                if(i==int(AtCoder[j]-'a')){
                    ok=true;
                    break;
                }
            }
            if(ok){
                if(cards[0][i]){
                    int delta=min(cards[0][i],cards[1][26]);
                    if(cards[0][i]-delta>0){
                        // cout<<i<<endl;
                        // cout<<cards[1][26]<<endl;
                        cout<<"No"<<endl;
                        return 0;
                    }
                }else{
                    int delta=min(cards[1][i],cards[0][26]);
                    if(cards[1][i]-delta>0){
                        // cout<<i<<" x"<<endl;
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            }else{
                // cout<<i<<'o'<<char('a'+i)<<endl;
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
/*

*/