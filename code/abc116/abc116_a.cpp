#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector <int> A(3);
    cin >>A[0]>>A[1]>>A[2];
    sort(A.begin(),A.end());
    int ans=A[0]*A[1]/2;
    cout <<ans;
}