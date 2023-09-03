#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    int N,Y,dif,A=10000,B=5000,C=1000;
    cin>>N>>Y;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            dif=Y-(A*i+B*j);
            if(dif<0){
                break;
            }else if(dif/C==N-(i+j)){
                cout<<i<<endl<<j<<endl<<N-(i+j)<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl<<-1<<endl<<-1<<endl;
    return 0;
}