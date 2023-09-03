/*
https://qiita.com/drken/items/ecd1a472d3a0e7db8dce#%E5%95%8F%E9%A1%8C-3abc-032-c-%E5%88%97
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

//区間最大長をとってそこから左端をインクリメントし、区間が0になったら右に伸ばしていく様が尺取虫のようだから尺取法？

int main(){
    int N;
    ll K;
    cin>>N>>K;
    vector<ll> S(N);
    bool check=false;
    rep(i,N){
        cin>>S[i];
        if(!S[i])check=true;
    }
    if(check){
        cout<<N<<endl;
        return 0;
    }

    int M=0,right=0;
    ll pro=1;
    rep(left,N){
        while(right<N&&pro*S[right]<=K){//半開区間であることに注意
            pro*=S[right];
            right++;
        }
        M=max(M,right-left);
        if(left==right)++right;//同値であるならば、rightを右に進め、leftより後ろにならないようにする
        else pro/=S[left];//左端の更新処理
    }
    cout<<M<<endl;

    return 0;
}

//a=97,z=122