//https://atcoder.jp/contests/abc094/submissions/8948179
//参考にさせて頂いたコード

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
    int N,pre=0;
    cin>>N;
    vector<int> A(N);
    ll sum=0;
    rep(i,N){
        cin>>A[i];
        sum+=abs(pre-A[i]);
        pre=A[i];
    }
    sum+=abs(pre);
    pre=0;
    rep(i,N){
        ll ANS;
        if(i==N-1){
            ANS=sum-abs(pre-A[i])-abs(A[i]);
            ANS+=abs(pre);
        }
        else{
            ANS=sum-abs(pre-A[i])-abs(A[i]-A[i+1]);
            ANS+=abs(pre-A[i+1]);
            pre=A[i];
        }
        cout<<ANS<<endl;
    }
    return 0;
}

//a=97,z=122