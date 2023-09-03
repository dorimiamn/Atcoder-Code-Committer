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
    int N,F[101][15],P[101][15];
    cin>>N;

    rep(i,N){
        rep(j,10){
            cin>>F[i][j];
        }
    }
    rep(i,N){
        rep(j,11){
            cin>>P[i][j];
        }
    }

    //bit全探索？
    int res=-INF;
    for(int b=1;b<(1<<10);b++){//営業するしないが10回選択できるため、10**2通りある
        int cc=0;
        for(int i=0;i<N;i++){
            int c=0;
            //b>>jが日にち指定 &1でその日営業するか否か
            for(int j=0;j<10;j++)if((b>>j&1)&&F[i][j])c++;//bitの各桁が営業日を表す？
            cc+=P[i][c];
        }
        if(res<cc)res=cc;
    }
    cout<<res<<endl;


    return 0;
}

//a=97,z=122