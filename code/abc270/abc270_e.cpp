//解説AC
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=10000000000000;
const int INF=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    ll N,K;
    cin>>N>>K;
    vi a(N);
    rep(i,N)cin>>a[i];

    ll ok=-1,ng=LongINF;
    while(ng-ok>1){
        ll mid=(ok+ng)/2;
        ll cnt=0;
        vi b=a;
        rep(i,N){
            if(b[i]>mid){
                cnt+=mid;
                b[i]-=mid;
            }
            else {
                cnt+=b[i];
                b[i]=0;
            }
        }

        if(cnt<=K){
            ok=mid;
        }else{
            ng=mid;
        }

    }

    ll cnt=0;
    rep(i,N){
        if(a[i]>ok){
            cnt+=ok;
            a[i]-=ok;
        }else{
            cnt+=a[i];
            a[i]=0;
        }
    }

    cnt=K-cnt;
    int index=0;
    while(cnt){
        if(!a[index]){
            index++;
            continue;
        }
        a[index]--;
        cnt--;
        index=(index+1)%N;
    }

    for(auto x:a)cout<<x<<endl;
    // cout<<""<<cnt<<endl;

    return 0;
}
/*
かごから何個食べるかを二分探索する
引き損ねた数を再分配とかするのかな
端数は愚直にやっていいのかー
*/