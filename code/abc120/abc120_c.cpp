#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll INF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int ans=0,N,z=0,o=0;
    string S;
    cin>>S;
    N=S.length();
    for(int i=0;i<N;i++){
        if(S[i]=='0')z++;
        else o++;
    }
    if(z<o){
        ans=z*2;
    }else{
        ans=o*2;
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122