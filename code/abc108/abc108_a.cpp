#include <iostream>

using namespace std;

int main(){
    int K;
    cin>>K;
    int Even=K/2;
    int Odd=K-Even;
    int ans=Even*Odd;
    cout <<ans;
    return 0;
}