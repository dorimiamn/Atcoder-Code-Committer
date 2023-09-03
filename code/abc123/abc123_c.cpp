#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll INF=1e13+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll N,TP[5];
    cin>>N;
    rep(i,5)cin>>TP[i];
    ll min=1e16;
    rep(i,5)if(min>TP[i])min=TP[i];
    ll ans=ceil(double(N)/double(min))+4;
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122