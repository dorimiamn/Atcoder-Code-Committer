#include <iostream>
#include <string>

using namespace std;

int main(){
    string s,ans;
    cin >>s;
    for(int i=0;i<s.length();i++){
        if(i%2==0){
            ans+=s[i];
        }
    }
    cout <<ans<<endl;
    return 0;
}