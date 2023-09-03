#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll INF=1e13+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,Q,A[100020],B[100020];
    string S;
    cin>>N>>Q>>S;
    rep(i,Q)cin>>A[i]>>B[i];
    int t[100020];
    t[0]=0;
    for(int i=0;i<N-1;i++){
        if(S[i]=='A'&&S[i+1]=='C')t[i+1]=t[i]+1;
        else t[i+1]=t[i];
    }
    for(int i=0;i<Q;i++){
        cout<<t[B[i]-1]-t[A[i]-1]<<endl;
    }
    cout<<endl;
    return 0;
}

//a=97,z=122