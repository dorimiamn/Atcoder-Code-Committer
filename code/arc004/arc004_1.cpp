#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int N;
    double X[101],Y[101],a,b,max=0.0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin >>X[i]>>Y[i];
    }
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(X[i]>X[j]){
                a=X[i]-X[j];
                a=a*a;
            }else{
                a=X[j]-X[i];
                a=a*a;
            }
            if(Y[i]>Y[j]){
                b=Y[i]-Y[j];
                b=b*b;
            }else{
                b=Y[j]-Y[i];
                b=b*b;
            }
            if(max<a+b){
                max=a+b;
            }
        }
    }
    cout<<sqrt(max)<<endl;
    return 0;
}