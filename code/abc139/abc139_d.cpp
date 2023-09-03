#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    long long count=0;
    cin>>N;
    for(int i=1;i<N;i++){
        count+=i;
    }
    cout<<count<<endl;
    return 0;
}