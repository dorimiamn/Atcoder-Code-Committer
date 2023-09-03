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
    int N,count=0;
    string S;
    cin>>N>>S;
    rep(i,N){
        if(i==N-1)continue;
        string stamp=S.substr(i,2);
        if(stamp=="OX"||stamp=="XO"){
            count++;
            i++;
        }
    }
    cout<<count<<endl;
    return 0;
}

//a=97,z=122