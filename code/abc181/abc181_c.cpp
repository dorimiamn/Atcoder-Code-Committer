//解説AC
//数学的素養がやっぱり足りない
//for文て判定書かなくても暗黙的に変数>=0で回してくれる?
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
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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
    int n;
    cin>>n;
    vector<pair<int,int>> p(n);
    for(auto& [x,y]:p)cin>>x>>y;
    for(int i=n;i--;)for(int j=i;j--;)for(int k=j;k--;){
        auto[x1,y1]=p[i];
        auto[x2,y2]=p[j];
        auto[x3,y3]=p[k];
        x1-=x3;
        x2-=x3;
        y1-=y3;
        y2-=y3;
        if(x1*y2==x2*y1){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}

//a=97,z=122