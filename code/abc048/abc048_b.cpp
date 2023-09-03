#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    long long a,b,x,count=0;
    cin>>a>>b>>x;
    long long div=a/x;
    if(a%x!=0){
        div++;
    }
    long long div1=b/x;
    count=div1-div+1;
    if(count<0)count=0;
    cout<<count<<endl;
    return 0;
}