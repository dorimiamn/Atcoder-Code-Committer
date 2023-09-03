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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

double n(double key){
    double ans=0.0;
    double L=0.0,R=key/3,mid=0.0;
    int cnt=0;
    //cout<<key-3*mid<<endl;
    while(key-(3*mid)>=0.00001){
        mid=L+(R-L)/2;
        if(key>3*mid)L=mid;
        else R=mid;
        //cout<<R<<" "<<L<<" "<<mid<<" "<<key-(3*mid)<<endl;
        //cout<<endl;
        if(cnt==11)break;
        cnt++;
    }
    return R*R*R;
}

//直方体
int main(){
    double L;
    cin>>L;
    cout<<decimal(10)<<n(L)<<endl;
    return 0;
}

//a=97,z=122