#include <iostream>

using namespace std;

int main(){
    int N,W[100],ans1=0,ans2=0,ans=10000;
    cin >>N;
    for(int i=0;i<N;i++){
        cin >>W[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j<=i){
                ans1=ans1+W[j];
            }else{
                ans2=ans2+W[j];
            }
        }
    if(ans1>ans2){
        ans1=ans1-ans2;
    }else{
        ans1=ans2-ans1;
    }
    ans=min(ans1,ans);
    ans1=0,ans2=0;
    }
    cout <<ans<<endl;
}