//https://www.utakata.work/entry/2015/05/19/123211
//http://yumandroid.blogspot.com/2015/09/abc023-c.html
//勉強させていただいた解説

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
    int R,C,K,N;
    cin>>R>>C>>K>>N;
    vector<int> xr(R,0),xc(C,0),r(N),c(N),rc(N,0),cc(N,0);
    rep(i,N){
        cin>>r[i]>>c[i];
        r[i]--,c[i]--;
        xr[r[i]]++,xc[c[i]]++;
    }

    rep(i,R)rc[xr[i]]++;//飴がn個ある行が何個あるかcount
    rep(i,C)cc[xc[i]]++;

    ll cnt=0;
    rep(i,K+1){//公式解説
        cnt+=rc[i]*cc[K-i];
    }
    rep(i,N){//差し引きがわからなかった
        int sum=xr[r[i]]+xc[c[i]];//i番目の列、行にある雨の数を足す
        //中々単純だった……
        //公式解説
        if(sum==K)cnt--;
        if(sum==K+1)cnt++;
    }

    cout<<cnt<<endl;



    return 0;
}

//a=97,z=122