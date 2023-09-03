#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N,D,ans=0,count=0;
    cin>>N>>D;
    int X[N][D];
    for(int i=0;i<N;i++){
        for(int j=0;j<D;j++){
            cin >>X[i][j];
        }
    }
    for(int i=0;i<N-1;i++){
        for(int k=i+1;k<N;k++){
            int  check=0;
            for(int j=0;j<D;j++){
                int  a=abs(X[i][j]-X[k][j]);
                check+=a*a;
            }
            for(int l=0;l<=check;l++){
                if(check==l*l){
                    count++;
                    break;
                }
            }
        }
    }
    cout<<count;
    return 0;
}