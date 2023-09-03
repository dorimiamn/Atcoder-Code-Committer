#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int a[3],d;
    cin>>a[0]>>a[1]>>a[2]>>d;
    int x=a[0]-a[2];
    if(x<0){
        x*=-1;
    }
    sort(a,a+3);
    if(a[2]-a[1]<=d&&a[1]-a[2]<=d||x<=d){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}