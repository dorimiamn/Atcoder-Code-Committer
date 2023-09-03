#include <iostream>

using namespace std;

int main(){
    long long L,R,mod=2019;
    cin>>L>>R;
    int ans=3000;
    if(R-L+1>=2019){
        cout<<0<<endl;
        return 0;
    }
    for(long long i=L;i<=R-1;i++){
        for(long long j=i+1;j<=R;j++){
            int a=(i*j)%mod;
            ans=min(a,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}