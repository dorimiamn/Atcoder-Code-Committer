#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int H,W,count=0;
    cin>>H>>W;
    string S[52];
    for(int i=0;i<H;i++)cin>>S[i];
    bool ans=false;
    for(int i=1;i<H;i++){
        for(int j=1;j<W;j++){
            if(S[i][j]=='#'&&S[i][j-1]!='#'&&S[i][j+1]!='#'&&S[i-1][j]!='#'&&S[i+1][j]!='#')count++;
        }
    }
    if(count==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}