#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>

using namespace std;


long long func(long long n,long long a,vector<long long> &dp,long long sum,long long nowsum){
    if(n==0) return sum+nowsum;
    a++;
    return func(n-1,a,dp,sum,nowsum*10+dp[a]) + func(n-1,a,dp,nowsum+sum,0);
}

int main(){
    long long S;
    vector<long long> NS;
    cin>>S;
    while(S){
        NS.push_back(S%10);
        S/=10;
    }
    reverse(NS.begin(),NS.end());
    int digit=NS.size();
    cout<<func(digit,-1,NS,0,0)<<endl;
    return 0;
}