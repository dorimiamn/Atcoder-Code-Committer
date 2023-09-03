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

//累積和？
//各駅間の時間をメモ、また総和もメモ


int main(){
    int N;
    cin>>N;
    vector<int> C(N),S(N),F(N),ANS(N,0);
    rep(i,N-1)cin>>C[i]>>S[i]>>F[i];


    for(int j=0;j<N-1;j++){
        ll time=0;
        REP(i,j,N-1){
        if(time<S[i]){
            time=S[i]+C[i];
        }else{
            int a=time%F[i];
            if(a==0)time+=C[i];
            else{
                time-=a;
                time+=F[i]+C[i];
            }
        }
        }
        cout<<time<<endl;
    }
    cout<<0<<endl;


    return 0;
}

//a=97,z=122