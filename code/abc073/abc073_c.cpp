#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,a,count=0;
    cin>>N;
    map<int,int> A;
    for(int i=0;i<N;i++){
        cin>>a;
        if(A[a]==0) A[a]++;
        else A[a]--;
    }
    for(auto itr =A.begin();itr!=A.end();itr++){
        if(itr->second==1){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}