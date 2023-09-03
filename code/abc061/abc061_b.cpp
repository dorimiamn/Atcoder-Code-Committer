#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int N,M,a,b;
    cin>>N>>M;
    vector<int> B(N,0);
    for(int i=0;i<M;i++){
        cin>>a>>b;
        B[a-1]++;
        B[b-1]++;
    }
    for(int i=0;i<N;i++){
        cout<<B[i]<<endl;
    }
    return 0;
}