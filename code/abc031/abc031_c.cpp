//http://mmxsrup.hatenablog.com/entry/2016/09/22/174141
//勉強させていただいた記事

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
    int N,ANS=-INF;
    cin>>N;
    vector<int> S(N);
    rep(i,N){
        cin>>S[i];
    }
    rep(i,N){
        int t,AO=-INF;
        rep(j,N){
            if(i==j)continue;
            int taka=0,aoki=0,cnt=1;
            REP(k,min(i,j),max(i,j)+1){
                if(cnt%2==1)taka+=S[k];
                else aoki+=S[k];
                cnt++;
            }
            if(AO<aoki){
                AO=aoki;
                t=taka;
            }
        }
        ANS=max(ANS,t);
    }

    cout<<ANS<<endl;
    return 0;
}
