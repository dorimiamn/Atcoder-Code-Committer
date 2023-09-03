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
    ll N,A,B;
    cin>>N>>A>>B;
    if((A-B)%2==0){
        cout<<(B-A)/2<<endl;
    }else{//終わりだけでなく途中も？
        ll H;
        if(N%2==1)H=(N+1)/2;
        else H=N/2;
        if((A<H&&B<=H)||(A>H&&B>H)){
            ll ANS1=min(N-A,B-1);
            ll D=min(A,N-B)+1;//回数
            ll ANS2;
            if(A<=N-B){//cause
                ANS2=D+(B-D-1)/2;
            }else{
                ANS2=D+(N-(A+D))/2;
            }
            cout<<min(ANS1,ANS2)<<endl;
        }else{
            ll H=min(A,N-B)+1;//回数
            if(A<=N-B){//cause
                cout<<H+(B-H-1)/2<<endl;
            }else{
                cout<<H+(N-(A+H))/2<<endl;
            }
        }
    }


    return 0;
}

//1 2 3 4 5 6 7 8
//  A         B
//A       B    after2
//  A   B   after3
//    A    after 4
//考えるのは、偶数になったときと同様
//1 2 3 4 5 6 7 8 9
//A               B
//1 2 3 4 5 6 7 8 9
//  A         B
//    4
/*
      A     B
1 2 3 4 5 6 7 8 9
  A     B




*/



//a=97,z=122
