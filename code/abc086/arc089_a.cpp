#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin>>N;
    N++;
    int t[N],x[N],y[N];
    t[0]=0,x[0]=0,y[0]=0;
    for(int i=1;i<N;i++){
        cin>>t[i]>>x[i]>>y[i];
    }
    bool ans=true;
    for(int i=0;i<N-1;i++){
        int a=t[i+1]-t[i];
        int b=abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
        if(a%2!=b%2){
            ans=false;
            break;
        }
        if(a<b){
            ans=false;
            break;
        }
    }
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}