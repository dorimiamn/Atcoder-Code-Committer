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
    ll Co=0,Bp=1;

    for(int memo=1;memo<N;memo++){
        bool t=true;
        for(int i=Bp;i<=N;i++){
            if(A[i-1]==memo){
                Co+=(i-Bp);
                Bp=i+1;
                t=false;
                break;
            }
        }
        if(t){
            if(memo==1){
                cout<<-1<<endl;
                return 0;
            }else{
                if(Bp<=N)Co+=(N-Bp+1);
                break;
            }
        }
    }

    if(Co==N)cout<<-1<<endl;
    else{
        cout<<Co<<endl;
    }

    return 0;
}

//a=97,z=122