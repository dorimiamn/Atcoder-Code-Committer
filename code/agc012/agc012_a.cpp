#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    long long ans=0;
    cin>>N;
    vector<long long> a(3*N);
    for(int i=0;i<3*N;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<N;i++){
        ans+=a[i*2+1];
    }
    cout<<ans<<endl;
    return 0;
}