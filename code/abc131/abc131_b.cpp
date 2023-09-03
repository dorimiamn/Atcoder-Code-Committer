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

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,L,sum=0,min=99999999,ans;
    cin>>N>>L;
    for(int i=0;i<N;i++){
        sum+=L+i;
    }
    for(int i=0;i<N;i++){
        int a=sum-i-L;
        if(abs(sum-a)<min) min=abs(sum-a),ans=a;
    }
    cout<<ans<<endl;
    return 0;
}