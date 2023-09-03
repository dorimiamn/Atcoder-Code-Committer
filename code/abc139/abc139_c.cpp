#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N,max=0;
    cin>>N;
    vector<int> H(N);
    for(int i=0;i<N;i++){
        cin>>H[i];
    }
    for(int i=0;i<N-1;i++){
        if(max>N-i-2){
            break;
        }
        int count=0;
        for(int j=i;j<N-1;j++){
            if(H[j]>=H[j+1]){
                count++;
            }else{
                break;
            }
        }
        if(max<count){
            max=count;
        }
    }
    cout<<max<<endl;
    return 0;
}