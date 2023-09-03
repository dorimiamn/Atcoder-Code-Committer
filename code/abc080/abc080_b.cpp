#include <iostream>
#include <cmath>

using namespace std;

int digit_sum(int num){
    if(num==0) return 0;
    return num%10+digit_sum(floor(num/10));
}

int main(){
    int N;
    cin >>N;
    int X=digit_sum(N);
    if(N%X==0){
        cout <<"Yes"<<endl;
    }else{
        cout <<"No"<<endl;
    }
    return 0;
}