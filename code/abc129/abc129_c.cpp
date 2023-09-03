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

vector<ll> memo(999999,-1);
map<ll,ll> a;

const ll mod=1e9+7;

ll dp(ll n){
    if(n==0) return 1;
    else if(a[n]==1) return 0;
    if(memo[n]!=-1) return memo[n];
    return memo[n]=(dp(n-1)+dp(n-2))%mod;
}

int main(){
    int N,M;
    cin>>N>>M;
    rep(i,M){
        int A;
        cin>>A;
        a[A]=1;
    }
    memo[0]=1;
    if(a[0]==1)memo[1]=0;
    else memo[1]=1;
    cout<<dp(N)<<endl;
    return 0;
}