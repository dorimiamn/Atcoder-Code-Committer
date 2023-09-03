#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    int N,K,a;
    cin>>N>>K;
    map<int,int> A;
    for(int i=0;i<N;i++){
        cin>>a;
        A[a]++;
    }
    a=0;
    int Ele=A.size();
    int B[Ele];
    for(auto itr=A.begin();itr!=A.end();itr++){
        B[a]=itr->second;
        a++;
    }
    a=0;
    sort(B,B+Ele);
    for(int i=0;i<Ele-K;i++){
        a+=B[i];
    }
    cout<<a;
    return 0;
}