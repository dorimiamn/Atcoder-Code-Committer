#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>

using namespace std;

int main(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int min1,min2;
    if(A<B){
        min1=A;
    }else{
        min1=B;
    }
    if(C<D){
        min2=C;
    }else{
        min2=D;
    }
    cout<<min1+min2<<endl;
    return 0;
}