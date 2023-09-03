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
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)


int main(){
    int N;
    cin>>N;
    vi A(N+1),box(N+1,0);
    rep(i,N)cin>>A[i+1];
    box[N]=A[N];
    for(int i=N-1;i>0;i--){
        int sum=0;
        for(int j=i*2;j<=N;j+=i){
            sum+=box[j];
        }
        if(sum%2==A[i])box[i]=0;
        else box[i]=1;
    }
    int M=0;
    vi ans;
    REP(i,1,N+1){
        M+=box[i];
        if(box[i]){
            ans.pb(i);
        }
    }
    cout<<M<<endl;
    rep(i,ans.size()){
        cout<<ans[i]<<" ";
        if(ans.size()-1==i)cout<<endl;
    }
    return 0;
}

//a=97,z=122