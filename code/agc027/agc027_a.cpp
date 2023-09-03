#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N,x,ans=0;
    cin>>N>>x;
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<N;i++){
        x-=a[i];
        if(N-1==i&&x!=0){
            cout<<ans;
            return 0;
        }else if(x>=0){
            ans++;
        }else{
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}