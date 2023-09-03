#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,T,min=9999999;
    cin>>N>>T;
    int c[N],t[N];
    rep(i,N) {
        cin>>c[i]>>t[i];
        if(t[i]<=T&&min>c[i]) min=c[i];
    }
    if(min==9999999) {
        cout<<"TLE"<<endl;
        return 0;
    }
    cout<<min<<endl;
    return 0;
}

//a=97,z=122