#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    long long N;
    int min=99;
    cin>>N;
    long long RN=sqrt(N);
    for(long long i=1;i<=RN;i++){
            if(N%i==0){
            int j=N/i;
            string C1=to_string(i);
            int digit1=C1.length();
            string C2=to_string(j);
            int digit2=C2.length();
            if(digit1<digit2) digit1=digit2;
            if(min>digit1) min=digit1;
            }
            if(i*i==N) break;
    }
    cout<<min;
    return 0;
}