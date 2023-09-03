#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    int ans=pow(K-1,N-1);
    cout<<ans*K<<endl;
    return 0;
}