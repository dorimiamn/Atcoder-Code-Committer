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
    vector<int> divisor(1001,0);
    //1000までの階乗の約数
    //前処理？
    for(int i=1;i<=N;i++){
        int A=i,d=2;
        while(A!=1&&d<=A){
            if(A%d==0){
                A/=d;
                divisor[d]++;
            }
            else d++;
        }
    }

    ll ANS=1;
    REP(i,1,N+1){
        ANS*=(divisor[i]+1);
        ANS%=INF;
    }
    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122