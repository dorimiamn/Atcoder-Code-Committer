#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int K,X;
    cin>>K>>X;
    for(int i=X-K+1;i<=X+K-1;i++){
        cout<<i<<endl;
    }
    return 0;
}