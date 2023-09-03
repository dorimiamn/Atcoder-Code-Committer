#include <iostream>
using namespace std;

int main(){
    int n;
    cin >>n;
    int digit3=n/100;
    int digit2=n-digit3*100;
    digit2=digit2/10;
    int digit1=n-digit3*100-digit2*10;
    if(digit3==9){
        digit3=1;
    }else if(digit3==1){
        digit3=9;
    }
    if(digit2==9){
        digit2=1;
    }else if(digit2==1){
    digit2=9;
    }
    if(digit1==9){
        digit1=1;
    }else if(digit1==1){
        digit1=9;
    }
    cout <<digit3*100+digit2*10+digit1;
    return 0;
}