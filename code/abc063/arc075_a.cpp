#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

//総和を出す。そこから、10で割れない数を引く

int main(){
    int N,sum=0,M=INF;
    cin>>N;
    vector<int> A(N);
    rep(i,N){
        cin>>A[i];
        sum+=A[i];
        if(A[i]%10!=0)M=min(M,A[i]);
    }
    if(M==INF)cout<<0;
    else if(sum%10!=0)cout<<sum<<endl;
    else cout<<sum-M<<endl;


    return 0;
}

//a=97,z=122