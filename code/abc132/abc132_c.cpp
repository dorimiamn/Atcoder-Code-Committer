#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,check1=0,count=0;
    int d[100000];
    cin>>N;
    int halfN=N/2-1;
    for(int i=0;i<N;i++) cin >>d[i];
    sort(d,d+N);
    cout<<d[N/2]-d[N/2-1]<<endl;
}