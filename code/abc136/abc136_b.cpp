#include <iostream>
#include <string>

using namespace std;

int main(){
    int N,count=0;
    cin >>N;
    string a;
    a=to_string(N);
    int A=a.length();
    if(A==2){
        cout <<9;
    }else if(A==4){
        cout <<909;
    }else if(A==6){
        cout <<90909;
    }else if(A==1){
        cout <<N;
    }else if(A==3){
        cout <<9+N-99;
    }else if(A==5){
        cout <<9+900+N-9999;
    }
    return 0;
}