#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    int AB[3][3];
    int b[3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>AB[i][j];
        }
    }
    for(int a=0;a<=100;a++){
        b[0]=AB[0][0]-a;
        b[1]=AB[0][1]-a;
        b[2]=AB[0][2]-a;
        if(AB[1][0]-b[0]==AB[1][1]-b[1]&&AB[1][1]-b[1]==AB[1][2]-b[2]&&AB[2][0]-b[0]==AB[2][1]-b[1]&&AB[2][1]-b[1]==AB[2][2]-b[2]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}