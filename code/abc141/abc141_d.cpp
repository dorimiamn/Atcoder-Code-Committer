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

int main(){
    int N,M;
    cin>>N>>M;
    priority_queue<long long> A;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        A.push(a);
    }
    for(int i=1;i<=M;i++){
        int a=A.top();
        A.pop();
        a=floor(a/2);
        A.push(a);
    }
    long long ans=0;
    for(int i=0;i<N;i++){
        ans+=A.top();
        A.pop();
    }
    cout<<ans<<endl;
    return 0;
}