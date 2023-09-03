#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string S;
    cin>>S;
    int A[26]={0};
    for(int i=0;i<S.length();i++){
        A[S[i]-97]++;
    }
    for(int i=0;i<26;i++){
        if(A[i]==0){
            cout<<char('a'+i)<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}