#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,max=0;
    cin>>N;
    int A[2][N];
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<N;i++){
        int a=0,b=0;
        for(int j=0;j<N;j++){
            if(j==i){
                b=1;
                a+=A[0][j];
            }
            a+=A[b][j];
        }
        if(a>max)max=a;
    }
    cout<<max<<endl;
    return 0;
}