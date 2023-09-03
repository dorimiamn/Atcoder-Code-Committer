#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll INF=1e13+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    char A,B;
    cin>>A>>B;
    int a=A,b=B;
    if(a<b){
        cout<<"<"<<endl;
    }else if(a==b){
        cout<<"="<<endl;
    }else{
        cout<<">"<<endl;
    }
    return 0;
}

//a=97,z=122