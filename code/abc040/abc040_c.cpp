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

using namespace std;

typedef long long ll;

ll a[999999];
vector<ll> memo(999999,-1);

#define rep(i,n) for(int i=0;i<(n);i++)

ll dp(ll n){
    if(n==0) return 0;
    else if(n==1) return memo[1];

    if(memo[n]!=-1) return memo[n];
    return memo[n]=min(abs(a[n]-a[n-1])+dp(n-1),abs(a[n]-a[n-2])+dp(n-2));
}

int main(){
    int N;
    cin>>N;
    rep(i,N) cin>>a[i];
    memo[0]=0;
    memo[1]=abs(a[1]-a[0]);
    cout<<dp(N-1)<<endl;
    return 0;
}