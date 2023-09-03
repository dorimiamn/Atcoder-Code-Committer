#include <iostream>
#include <cmath>
using namespace std;

int digit_sum(int num){
    if(num==0) return 0;
    return num%10+digit_sum(floor(num/10));
}

int main(){
    int N,min=999999;
    cin>>N;
    for(int i=1;i<N;i++){
        int a=digit_sum(i);
        int b=digit_sum(N-i);
        if(min>a+b){
            min=a+b;
        }
    }
    cout<<min<<endl;
    return 0;
}