#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    int N,M,max=0,count=0;
    vector<string> C(201);
    cin>>N;
    map<string,int> BR;
    for(int i=0;i<N;i++){
        cin>>C[count];
        BR[C[count]]++;
        count++;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>C[count];
        BR[C[count]]--;
        count++;
    }
    for(int i=0;i<=count;i++){
        if(BR[C[i]]>max) max=BR[C[i]];
    }
    cout<<max;
    return 0;
}