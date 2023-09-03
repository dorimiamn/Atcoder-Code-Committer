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

double P;

double calc(double x){
    return x+P/(pow(2,x/1.5));
}

int main(){
    cin>>P;
    
    double right=1e18,left=0;
    while(right-left>1e-8){
        double m1=(2*right+left)/3,m2=(right+2*left)/3;
        double res1=calc(m1),res2=calc(m2);
        if(res1<res2)left=m2;
        else right=m1;
        // cout<<right<<" "<<left<<" "<<res1<<" "<<res2<<endl;
    }

    cout<<decimal(9)<<calc(right)<<endl;

    return 0;
}

/*
計算を始めるまでの時間を三分探索で求める
三分探索を用いると1つ凸を持つ関数において、凸の部分を求めることが可能。
非直感的だが、二分探索に滑り止めをつけたようなものだって理解をしている。
ちゃんと証明をおった方が良さそう。
*/