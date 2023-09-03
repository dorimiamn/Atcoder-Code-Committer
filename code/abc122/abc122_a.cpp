#include <iostream>

using namespace std;

int main(){
char s;
cin >>s;
    if(s=='A'){
        s='T';
    }else if(s=='C'){
        s='G';
    }else if(s=='T'){
        s='A';
    }else{
        s='C';
    }
  cout <<s;
return 0;
}