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

ll L[999999];
vector<ll> memo(999999,-1);
ll N;

#define rep(i,n) for(int i=0;i<(n);i++)

ll dp(ll n){
    if(n==1) return abs(L[0]-L[1]);
    else if(n==0) return 0;
    
    if(memo[n]!=-1) return memo[n];
    return memo[n]=min(dp(n-1)+abs(L[n]-L[n-1]),dp(n-2)+abs(L[n]-L[n-2]));
}

int main(){
    cin>>N;
    rep(i,N) cin>>L[i];
    memo[0]=0;
    cout<<dp(N-1);
    return 0;
}