/*
https://drken1215.hatenablog.com/entry/2020/01/12/135000
勉強させていただいた記事
*/


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
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()


int main(){
    ll N,M;
    cin>>N>>M;
    vector<ll> A(N);
    rep(i,N){
        cin>>A[i];
        A[i]/=2;
    }
    while(A[0]%2==0){
        rep(i,N){
            if(A[i]%2!=0){
                cout<<0<<endl;
                return 0;
            }
            A[i]/=2;
        }
        M/=2;
    }
    rep(i,N)if(A[i]%2==0){
        cout<<0<<endl;
        return 0;
    }
    ll lcm=1;
    rep(i,N){
        lcm=LCM(lcm,A[i]);
        if(lcm>M){
            cout<<0<<endl;
            return 0;
        }
    }
    //M/lcmでLの個数を求め、それを2で割ることで奇数を取り出している
    cout<<(M/lcm+1)/2<<endl;

    return 0;
}

//a=97,z=122

/*
小数が含まれてる時は、消すことを考えよう
a[k]%2==1の場合、Xは正の整数なので、条件を見たさず0
*/