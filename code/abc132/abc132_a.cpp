#include <iostream>

using namespace std;

int main(){
    char S[5];
    int a=0,b=0;
    cin >>S;
    if(S[0]==S[1]){
        a++;
        if(S[0]==S[2]){
            cout <<"No"<<endl;
        }else{
            if(S[2]==S[3]){
                cout <<"Yes"<<endl;
            }else{
                cout <<"No"<<endl;
            }
        }
    }
    else{
        if(S[0]==S[2]){
            if(S[1]==S[3]){
                cout <<"Yes"<<endl;
            }else
            {
                cout <<"No"<<endl;
            }
            
        }else{
            if(S[1]==S[2]){
                if(S[0]==S[3]){
                    cout <<"Yes";
                }else{
                    cout <<"No";
                }
            }else{
                if(S[0]==S[2]){
                    cout <<"Yes";
                }
                else{
                    cout <<"No";
                }
            }
        }
    }
}