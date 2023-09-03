#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    long long N;
    cin>>N;
    long long Div=1000000007;
    long long ans=1;
    for(long long i=1;i<=N;i++){
        ans=(ans*i)%Div;
    }
    cout<<ans<<endl;
    return 0;
}