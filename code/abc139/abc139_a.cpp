#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int count=0;
    string S,T;
    cin>>S>>T;
    for(int i=0;i<3;i++){
        if(S[i]==T[i]){
            count++;
        }
    }
    cout<<count;
    return 0;
}