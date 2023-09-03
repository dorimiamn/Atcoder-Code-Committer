#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int A=99999,Z=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A'&&A>i){
            A=i;
        }else if(s[i]=='Z'&&i>Z){
            Z=i;
        }
    }
    cout <<Z-A+1<<endl;
}