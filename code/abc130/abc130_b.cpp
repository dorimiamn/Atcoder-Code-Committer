#include <iostream>
using namespace std;

int main(){
    int N,X,L[100],sum=0,ans=1;
    cin >>N>>X;
    for(int i=0;i<N;i++){
        cin >>L[i];
    }
    for(int i=0;i<N;i++){
        sum=sum+L[i];
        if(sum<=X){
            ans++;
        }
    }
    cout <<ans<<endl;
    return 0;
}