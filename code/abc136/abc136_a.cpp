#include <iostream>

using namespace std;

int main(){
    int A,B,C;
    cin >>A>>B>>C;
    if(A<B+C){
        cout <<B+C-A;
        return 0;
    }else{
        cout <<0;
        return 0;
    }
}