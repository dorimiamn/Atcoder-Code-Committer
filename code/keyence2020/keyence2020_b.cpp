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

//計算量はNで行きたい
//配列で殴れるか……？
//むり

int main(){
    int N,ANS=0;
    cin>>N;
    vector<ll> X(N,0),L(N,0);
    vector<pair<ll,ll>> p;
    rep(i,N){
        cin>>X[i]>>L[i];
        p.pb(make_pair(X[i]+L[i],X[i]-L[i]));
    }
    sort(ALL(p));
    int C=-INF;

    rep(i,N){
        if(C<=p[i].second){//比較してるp[i]が腕の最前よりも前にあるなら、
            ANS++;
            C=p[i].first;//残すと決めた腕の一番最前を更新
        }
    }
    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122