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

#define rep(i,n) for(int i=0;i<(n);i++)


vector<ll> cost(100007,-1);
vector<ll> memo(100007,-1);
ll K,check=1e9+7;

ll dp(ll n){
    ll c=K;
    if(n==0) return 0;
    if(memo[n]!=-1) return memo[n];
    else memo[n]=check;
    if(n<K) c=n;
    for(ll i=1;i<=c;i++){
        memo[n]=min(dp(n-i)+abs(cost[n]-cost[n-i]),memo[n]);
    }
    return memo[n];
}

int main(){
    int N;
    cin>>N>>K;
    rep(i,N) cin>>cost[i];
    memo[0]=0;
    memo[1]=abs(cost[1]-cost[0]);
    cout<<dp(N-1)<<endl;
    return 0;
}