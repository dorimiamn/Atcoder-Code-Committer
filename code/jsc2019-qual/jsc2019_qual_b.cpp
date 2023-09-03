/*
勉強させて頂いた解説
https://scrapbox.io/pocala-kyopro/B_-_Kleene_Inversion
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const ll INF=1e9+7;
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

//modのとり方には注意

int main(){
    ll n,k;
    cin>>n>>k;
    vi a(n);
    rep(i,n)cin>>a[i];
    ll sum=0;
    rep(i,n){
        ll cnt1=0,cnt2=0;
        REP(j,i,n){
            if(a[i]>a[j])cnt2++;
        }
        rep(j,n){
            if(a[i]>a[j])cnt1++;
        }
        //cout<<"cnt:"<<cnt<<endl;
        sum+=(k*(k-1)/2)%INF*cnt1%INF;
        sum%=INF;
        sum+=cnt2*k%INF;
        sum%=INF;
    }
    cout<<sum<<endl;
    return 0;
}

//a=97,z=122