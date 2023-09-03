#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,sum=0,count=0;
    cin>>N;
    int A[N],B[N],C[N];
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    for(int i=0;i<N-1;i++) cin>>C[i];
    for(int i=0;i<N;i++){
        sum+=B[A[i]-1];
        if(A[i-1]+1==A[i]){
            sum+=C[A[i-1]-1];
        }
    }
    cout<<sum<<endl;
    return 0;
}