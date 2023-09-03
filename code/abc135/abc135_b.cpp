#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin>>N;
    int L[N];
    for(int i=0;i<N;i++)L[i]=i+1;
    int p[N];
    for(int i=0;i<N;i++) cin>>p[i];
    int check=0;
    for(int i=0;i<N;i++){
        if(L[i]!=p[i]){
            check++;
        }
    }
    if(check>2) cout<<"NO";
    else cout<<"YES";
    return 0;
}