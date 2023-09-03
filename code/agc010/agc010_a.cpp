#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,Oddnum=0,Evennum=0;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=0;i<N;i++){
        if(A[i]%2==0){
            Evennum++;
        }else{
            Oddnum++;
        }
    }
    if(Oddnum%2==1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}