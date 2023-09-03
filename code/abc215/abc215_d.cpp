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

int main(){
    int N,M;
    cin>>N>>M;
    vector<bool> numbers(M+1,true);
    vi ans;
    set<int> primes;
    rep(i,N){
        int a;
        cin>>a;
        REP(j,2,sqrt(a)+1){
            if(a%j==0)primes.insert(j);
            while(a%j==0){
                a/=j;
            }
        }
        if(a!=1)primes.insert(a);
    }

    for(auto prime:primes){
        for(int x=prime;x<=M;x+=prime)numbers[x]=false;
    }
    REP(i,1,M+1)if(numbers[i])ans.pb(i);
    
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}
/*
{A}の素因数を取り出すことは正しそう。
その後のiが{A}の任意の要素に対して素であるかの処理が重かった
素因数をn梅して、その分を消していけばよい
エラトステネスの篩の実装でやったやつだ……
*/