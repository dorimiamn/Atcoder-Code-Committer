#include <iostream>

using namespace std;

int main(){
    int A,B,count=0;
    cin >>A>>B;
    //常にA>B
    for(int i=0;i<40;i++){
        if(B>A){
            int a=B;
            B=A;
            A=a;
        }
        if(A-B>7){
            A-=10;
            count++;
        }else if(A-B>3){
            A-=5;
            count++;
        }else if(A-B>0){
            A-=1;
            count++;
        }else{
            cout <<count<<endl;
            return 0;
        }
    }
    return 0;
}