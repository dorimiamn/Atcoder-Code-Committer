#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,sumE=0,sumW=0,ans=999999;
    string S;
    cin>>N>>S;
    int West[N];
    int East[N];
    for(int i=0;i<N;i++){
        if(S[i]=='E'){
            sumE++;
            East[i]=sumE;
            West[i]=sumW;
        }else{
            sumW++;
            West[i]=sumW;
            East[i]=sumE;
        }
    }
    for(int i=0;i<N;i++){
        int sum=West[i]+East[N-1]-East[i];
        if(S[i]=='W')sum--;
        if(sum<ans)ans=sum;
    }
    cout<<ans<<endl;
    return 0;
}