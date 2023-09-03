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

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    double N,K,ans=0.0;
    int sum;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        sum=i;
        double probablity=1/N;
        while(sum<K){
            probablity*=0.5;
            sum*=2;
        }
        ans+=probablity;
    }
    cout<<setprecision(13)<<ans<<endl;
    return 0;
}

//a=97,z=122