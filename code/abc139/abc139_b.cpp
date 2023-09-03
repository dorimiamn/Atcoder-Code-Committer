#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int A,B,count=1;
    cin>>A>>B;
    if(B==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1; ;i++){
        count+=A-1;
        if(count>=B){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}