#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    int A,B,C,X,Y,D,E,F;
    long long min=999999999999;
    cin>>A>>B>>C>>X>>Y;
    for(int i=0;i<=200000;i++){
        D=i*2;
        E=X-i;
        F=Y-i;
        if(E<0) E=0;
        if(F<0) F=0;
        if(min>A*E+B*F+C*D){
            min=A*E+B*F+C*D;
        }
    }
    cout<<min<<endl;
    return 0;
}