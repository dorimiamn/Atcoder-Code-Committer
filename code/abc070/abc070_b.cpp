#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int right,left;
    if(A>C) left=A;
    else left=C;
    if(B>D)right=D;
    else right=B;
    int ans=right-left;
    if(ans<0)ans=0; 
    cout<<ans<<endl;
    return 0;
}