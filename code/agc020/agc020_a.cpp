#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,A,B;
    cin>>N>>A>>B;
    int a=abs(A-B)-1;
    if(N%2==0){
        if(a%2==0){
            cout<<"Borys"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
    }else{
        if(a%2==0){
            cout<<"Borys"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}