#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
string S;
cin>> S;
if(S[5]=='1'){
    cout <<"TBD";
    return 0;
}
S=S[6];
int k=stoi(S);
for(int i=1;i<5;i++){
    if(k==i){
        cout <<"Heisei";
        return 0;
    }
}
cout <<"TBD";
return 0;
}