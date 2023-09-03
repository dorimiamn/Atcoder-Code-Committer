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
    int N;
    cin>>N;
    int d[N];
    rep(i,N) cin>>d[i];
    int sum=0;
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            sum+=d[i]*d[j];
        }
    }
    cout<<sum<<endl;
    return 0;
}

//a=97,z=122