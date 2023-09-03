#include <iostream>

using namespace std;

int main(){
    int P,Q,R;
    cin >>P>>Q>>R;
    if(P>Q){
        if(P>R){
            cout <<Q+R;
        }
        else{
            cout <<P+Q;
        }
    }else{
        if(Q>R){
            cout <<P+R;
        }else{
            cout <<P+Q;
        }
    }
    return 0;
}