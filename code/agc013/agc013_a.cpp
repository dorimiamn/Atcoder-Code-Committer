#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,count=1;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++) cin>>A[i];
    int check=0;
    for(int i=0;i<N-1;i++){
        if(A[i]<A[i+1]){
            if(check==2){
                count++;
                check=0;
            }else check=1;
        }else if(A[i]>A[i+1]){
            if(check==1){
                count++;
                check=0;
            }else check=2;
        }
    }
    cout<<count;
    return 0;
}