#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N,count=1;
    cin>>N;
    vector<int> d(N);
    for(int i=0;i<N;i++){
        cin>>d[i];
    }
    sort(d.begin(),d.end(),greater<int>());
    for(int i=0;i<N-1;i++){
        if(d[i]>d[i+1]){
            count++;
        }
    }
    cout<<count;
    return 0;
}