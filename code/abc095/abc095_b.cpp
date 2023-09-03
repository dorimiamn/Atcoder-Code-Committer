#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N,M,X,sum=0,MIN=1001;
    cin>>N>>X;
    for(int i=0;i<N;i++){
        cin>>M;
        sum+=M;
        if(MIN>M){
            MIN=M;
        }
    }
    X=floor((X-sum)/MIN);
    cout <<N+X<<endl;
    return 0;
}