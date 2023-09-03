#include <iostream>

using namespace std;

int main(){
    int A,B;
    cin>>A>>B;
    int sum=A*B;
    if(sum*1%2==1||sum*3%2==1){
        cout <<"Yes";
        return 0;
    }else {
        cout <<"No";
        return 0;
    }
    return 0;
}