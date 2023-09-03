//http://keita-matsushita.hatenablog.com/entry/2017/04/19/150537
//勉強させていただいた記事

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

//等差数列を使うことでtまでの総和はO(1)で求まるようだ……
//数列の数ではなく現在のtに着目する
//tまでの総和がXを超えなかったらそれは全部とんでもたどり着かないと言うことと同義であるため

int main(){
    ll X,time=0,p=0;
    cin>>X;


    while(p<X){
        time++;
        p=(time*(time+1))/2;
    }
    cout<<time<<endl;


    return 0;
}

//a=97,z=122