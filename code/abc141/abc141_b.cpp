#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    string S;
    cin>>S;
    bool check=false;
    for(int i=0;i<S.length();i++){
        check=false;
        if(i%2==0){
            if(S[i]=='R'||S[i]=='U'||S[i]=='D'){
                check=true;
            }
        }else{
            if(S[i]=='L'||S[i]=='U'||S[i]=='D'){
                check=true;
            }
        }
        if(!check){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}