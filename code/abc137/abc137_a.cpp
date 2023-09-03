#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    int A,B;
    cin>>A>>B;
    int C[2];
    C[0]=A+B,C[1]=A-B,C[2]=A*B;
    sort(C,C+3);
    cout<<C[2];
    return 0;
}