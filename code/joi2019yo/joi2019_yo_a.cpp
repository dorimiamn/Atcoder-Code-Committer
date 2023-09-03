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
    int A,B,C,sum=0,day=0,ans=0;
    cin>>A>>B>>C;
    while(C>sum){
        if(day==6){
            sum+=A+B;
            day=0;
        }
        else{
            sum+=A;
            day++;
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122