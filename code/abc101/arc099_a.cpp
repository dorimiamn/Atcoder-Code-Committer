//http://drken1215.hatenablog.com/entry/2018/06/24/003500
//勉強させて頂いた記事

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

//8 3
//7 3 1 8 4 6 2 5
//13 12 11 10 7 3 8 1 9 4 6 2 5
//  |     |    5|     |

//言い換え大切
//別に1からやらなくても、左端からやっても結果は変わらない。
//左端からつめて、1にたどり着くということは逆も然りである。

int main(){
    int N,K;
    vector<int> A;
    while(cin>>N>>K){
        A.resize(N);
        rep(i,N)cin>>A[i];
        int res=0;
        int right=0;
        while(true){//シミュレーション
            if(res==0)right+=K;
            else right+=K-1;
            ++res;

            if(right>=N)break;
        }
        cout<<res<<endl;
    }

    return 0;
}

//a=97,z=122