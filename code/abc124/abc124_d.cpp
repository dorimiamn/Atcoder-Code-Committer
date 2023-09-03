//解説Submit
/*
https://atcoder.jp/contests/abc124/submissions/4938113
参考にさせていただいたSubmit
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
const int INF=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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
    int N,K;
    string S;
    cin>>N>>K>>S;
    vi arr(1,0);
    bool state;
    if(S[0]=='0')state=false;
    else state=true;
    REP(i,1,N){
        if(state&&S[i]=='0'){
            state=false;
            arr.pb(i);
        }
        if(!state&&S[i]=='1'){
            state=true;
            arr.pb(i);
        }
    }
    arr.pb(N);

    // for(auto x:arr)cout<<x<<" ";
    // cout<<endl;

    // cout<<"arr:"<<arr.size()<<endl;

    int ans=0;
    rep(i,arr.size()-1){
        int r=i+(S[arr[i]]=='0'?K*2:K*2+1);
        int t=arr[min(r,(int)arr.size()-1)]-arr[i];
        ans=max(ans,t);
        //誤読していた
        //S[i]が0か1かでKに1を加算するか変わるのではあって、先頭で判断するのではない。
    }

    cout<<ans<<endl;
    
    return 0;
}
/*
O(N)解法。
座圧して、01交互に集団が現れるのだから、先頭のインデックスのみで計算できるよね。
連続する文字列の先頭のみ記録しておけば良い？
*/