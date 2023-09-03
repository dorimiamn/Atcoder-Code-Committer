#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;
//2だけの増加もOK
int main(){
    int A[3],ans=0;
    cin>>A[0]>>A[1]>>A[2];
    sort(A,A+3);
    if(A[0]==A[1]&&A[1]==A[2]){
        cout<<ans<<endl;
        return 0;
    }
    for(int i=0; ; i++){
        if(A[1]-A[0]>1){
            A[0]+=2;
            ans++;
        }else{
            A[0]++;
            A[1]++;
            ans++;
        }
        sort(A,A+3);
        if(A[0]==A[1]&&A[1]==A[2]){
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}