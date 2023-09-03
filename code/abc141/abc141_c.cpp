#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,K,Q;
    cin>>N>>K>>Q;
    int A[Q],Point[N];
    for(int i=0;i<Q;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        Point[i]=0;
    }
    for(int i=0;i<Q;i++){
        Point[A[i]-1]++;
    }
    for(int i=0;i<N;i++){
        if(Q-Point[i]>=K){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}