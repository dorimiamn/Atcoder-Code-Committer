#include <iostream>

using namespace std;

int main (){
    int N,K;
    cin >>N>>K;
    N=N-K;
    if(K==1) N=0;
    cout <<N;
}