#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int W,H,N,ans=0;
    cin>>W>>H>>N;
    int X[N]={},Y[N]={},a[N]={};
    bool A[W+1][H+1]={false};
    for(int i=0;i<N;i++) cin>>X[i]>>Y[i]>>a[i];
    for(int i=0;i<N;i++){
        if(a[i]==1){
            for(int j=1;j<=X[i];j++){
                for(int k=1;k<=H;k++){
                    A[j][k]=true;
                }
            }
        }else if(a[i]==2){
            for(int j=X[i]+1;j<=W;j++){
                for(int k=1;k<=H;k++){
                    A[j][k]=true;
                }
            }
        }else if(a[i]==3){
            for(int j=1;j<=W;j++){
                for(int k=1;k<=Y[i];k++){
                    A[j][k]=true;
                }
            }
        }else{
            for(int j=1;j<=W;j++){
                for(int k=Y[i]+1;k<=H;k++){
                    A[j][k]=true;
                }
            }
        }
    }
    for(int j=1;j<=W;j++){
        for(int k=1;k<=H;k++){
            if(!A[j][k]) ans++;
        }
    }
    cout<<ans;
    return 0;
}