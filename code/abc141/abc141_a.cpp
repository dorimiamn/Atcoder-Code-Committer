#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    string S;
    cin>>S;
    if(S=="Sunny"){
        cout<<"Cloudy";
    }else if(S=="Cloudy"){
        cout<<"Rainy";
    }else{
        cout<<"Sunny";
    }
    return 0;
}