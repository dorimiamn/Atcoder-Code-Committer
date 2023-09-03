#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int digit_sum(int num){
    if(num==0) return 0;
    return num%10+digit_sum(floor(num/10));
}

int main(){
    int A,B,count=0;
    cin>>A>>B;
    for(int i=A;i<=B;i++){
        string a=to_string(i);
        string b=a;
        reverse(b.begin(),b.end());
        if(a==b){
            count++;
        }
    }
    cout <<count<<endl;
    return 0;
}