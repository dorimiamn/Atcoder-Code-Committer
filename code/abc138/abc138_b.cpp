#include <iostream>

using namespace std;

int main(){
    int N;
    double A,ans=0.0;
    cin >>N;
    for(int i=0;i<N;i++){
        cin>>A;
        ans+=1/A;
    }
    ans=1/ans;
    cout <<ans;
    return 0;
}