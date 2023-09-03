#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,b=0,count=1;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++) cin>>a[i];
    b=a[0];
    for(int i=0;i<N;i++){
        if(b==2){
            cout<<count<<endl;
            return 0;
        }else{
            b=a[b-1];
            count++;
        }
    }
    count=-1;
    cout<<count<<endl;
    return 0;
}