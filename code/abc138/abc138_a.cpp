#include <iostream>
#include <string>

using namespace std;

int main(){
    int a;
    string s;
    cin >>a;
    cin>>s;
    if(a>=3200){
        cout <<s;
        return 0;
    }else{
        cout <<"red";
        return 0;
    }
}