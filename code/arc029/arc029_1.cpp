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

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

ll N,t[10];

ll dp(ll n,ll t1,ll t2){
    if(n>N) return max(t1,t2);
    return min(dp(n+1,t1+t[n],t2),dp(n+1,t1,t2+t[n]));
}

int main(){
    cin>>N;
    rep(i,N){
        cin>>t[i];
    }
    cout<<dp(0,0,0)<<endl;
    return 0;
}

//参考https://atcoder.jp/contests/arc029/submissions/7582672