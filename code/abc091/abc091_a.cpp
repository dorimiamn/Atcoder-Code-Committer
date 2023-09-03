#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    if(A+B>=C){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}