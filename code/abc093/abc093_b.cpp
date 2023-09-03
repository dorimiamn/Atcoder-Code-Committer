#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int A,B,K,D,E;
    cin>>A>>B>>K;
    if(B-A<K){
        D=B+1;
        E=B+1;
    }else{
        D=A+K;
        E=B-K+1;
    }
    for(int i=A;i<D;i++){
        cout<<i<<endl;
        if(i+1==E) break;
    }
    for(int i=E;i<=B;i++){
        cout<< i<< endl;
    }
    return 0;
}

//a=97,z=122