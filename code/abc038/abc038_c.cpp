/*
https://qiita.com/drken/items/ecd1a472d3a0e7db8dce#3-%E3%81%97%E3%82%83%E3%81%8F%E3%81%A8%E3%82%8A%E6%B3%95%E3%82%92%E6%A7%98%E3%80%85%E3%81%AA%E8%A6%96%E7%82%B9%E3%81%8B%E3%82%89
勉強させていただいた記事
*/
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
    vector<int> A(N);
    rep(i,N)cin>>A[i];

    ll res=0;
    int right=1;
    rep(left,N){
        while(right<N&&(right<=left||A[right-1]<A[right])){
            right++;//区間を進められるかどうか
        }
        res+=right-left;//現在位置と照らし合わせて区間を足す
        if(left==right)++right;
    }
    cout<<res<<endl;

    return 0;
}

//a=97,z=122