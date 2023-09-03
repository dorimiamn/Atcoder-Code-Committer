#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N,A=0,B=0;
    cin>>N;
    vector<int> L(N);
    for(int i=0;i<N;i++){
        cin>>L[i];
    }
    //sort
    sort(L.begin(),L.end(),greater<int>());
    for(int i=0;i<N;i++){
        if(i%2==0){
            A+=L[i];
        }else{
            B+=L[i];
        }
    }
    cout <<A-B<<endl;
    return 0;
}