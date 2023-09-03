#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,border=0,H[100000],Highest=0;
    cin >>N;
    for(int i=0;i<N;i++){
        cin >>H[i];
    }
    for(int i=0;i<N-2;i++){
        if(H[i+1]-H[i]>1&&border<H[i+1]){
            border=H[i+1]-1;
        }
        if(H[i]>Highest){
            Highest=H[i]-1;
        }
        if(H[i+2]<border||Highest>H[i]){
            cout <<"No";
            return 0;
        }
    }
    cout <<"Yes";
    return 0;
}