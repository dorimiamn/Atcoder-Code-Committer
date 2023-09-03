#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

//2^3通り？

int main(){
    int A,B,C,D,S;
    string op1,op2,op3;
    cin>>S;
    D=S%10;
    S=S/10;
    C=S%10;
    S=S/10;
    B=S%10;
    S=S/10;
    A=S%10;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                int sum=A;
                if(i%2==0){
                    sum+=B;
                    op1='+';
                }else{
                    sum-=B;
                    op1='-';
                }
                if(j%2==0){
                    sum+=C;
                    op2='+';
                }else{
                    sum-=C;
                    op2='-';
                }
                if(k%2==0){
                    sum+=D;
                    op3='+';
                }else{
                    sum-=D;
                    op3='-';
                }
                if(sum==7){
                    cout<<A<<op1<<B<<op2<<C<<op3<<D<<"=7"<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}