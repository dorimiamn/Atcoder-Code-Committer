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


int send(int A,int B,int C,int D){
    int T;
    cout<<"? "<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    cin>>T;
    return T;
}

int main(){
    int N;
    cin>>N;
    //a,b,c,dの変数の意味を取り違えている。
    int U=1,D=N+1;
    while(D-U>1){
        int M=(U+D)/2;
        int t=send(U,M-1,1,N);
        if(t==M-U){
            U=M;
        }else{
            D=M;
        }
    }

    int L=1,R=N+1;

    while(R-L>1){
        int M=(L+R)/2;
        int t=send(1,N,L,M-1);
        if(t==M-L){
            L=M;
        }else{
            R=M;
        }
    }
    cout<<"!"<<" "<<U<<" "<<L<<endl;
    return 0;
}
/*
聞いた範囲に対して、行または列が返されるコマの数に一致すれば、その範囲におけるマスはない。
行と列それぞれで判定したら良いのでは？
つまり、一行ずつと一列ずつの判定で萎めていく。質問回数は最大で18回になるはず。
考察は正しいが、実装で詰まった。
whileで半開区間を考えて答えを出せばよかったみたい。
forだったからその部分の判定に詰まってしまった。
b-a<1としてたので、その部分が煮詰まらなくて冗長な処理を書いてしまった。
変数がとりうる値から大小関係は判別できて、それを上手く活用できてない？
半開区間の認識が足りてないかも。
*/