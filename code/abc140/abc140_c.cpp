#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N;
    long long sum=0;
    cin>>N;
    int A[N],B[N-1];
    for(int i=0;i<N-1;i++) cin>>B[i];
    A[0]=B[0];
    for(int i=0;i<N-2;i++){
        if(B[i]>B[i+1])A[i+1]=B[i+1];
        else {
            A[i+1]=B[i];
        }
    }
    A[N-1]=B[N-2];
    for(int i=0;i<N;i++){
        sum+=A[i];
    }
    cout<<sum<<endl;
    return 0;
}

//B>=max(A,A+1)
// 0 153 10 10 23
// 0,0,10,10,
//9 12 1
//9  9 1 1
//右下を確定させる