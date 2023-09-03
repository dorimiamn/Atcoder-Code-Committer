#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=1;i<=b;i++){
        if(a*i%b==c){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}