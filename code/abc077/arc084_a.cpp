//https://scrapbox.io/ganariya/AtCoderBeginnerContest077_C%E5%95%8F%E9%A1%8C300%E7%82%B9_%E3%80%8CSnuke_Festival%E3%80%8D_(copy)
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
    int N;
    cin>>N;
    vector<int> A(N),B(N),C(N);
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];
    rep(i,N)cin>>C[i];
    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(C));

    ll ans=0;

    rep(i,N){
        ll pre=lower_bound(A.begin(),A.end(),B[i])-A.begin();//イテレータは足し算、引き算ができる...!結果も正しく出る
        ll over=C.end()-upper_bound(C.begin(),C.end(),B[i]);//B[i]よりも大きい配列数
        ans+=pre*over;
    }

    cout<<ans<<endl;

    return 0;
}

//a=97,z=122