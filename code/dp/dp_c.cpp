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

const ll INF=1e9+7;

#define rep(i,n) for(int i=0;i<(n);i++)

vector<vector<ll> > memo(100007,vector<ll>(3,-1));
ll N;

int dp(vector<vector<int> > &ABC,ll i,ll j){
    if(i==0) return 0;

    if(memo[i][j]!=-1) return memo[i][j];
    return memo[i][j]=max(dp(ABC,i-1,(j+1)%3)+ABC[i][j],dp(ABC,i-1,(j+2)%3)+ABC[i][j]);
}

int main(){
    cin>>N;
    vector<vector<int> > ABC(N+1,vector<int>(3));
    ABC[0][0]=0,ABC[0][1]=0,ABC[0][2]=0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            cin>>ABC[i][j];
        }
    }
    cout<<max(max(dp(ABC,N,0),dp(ABC,N,1)),dp(ABC,N,2))<<endl;
    return 0;
}