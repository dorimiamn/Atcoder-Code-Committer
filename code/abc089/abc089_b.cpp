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
    int N;
    cin>>N;
    int one=0,two=0,thr=0,fou=0;
    rep(i,N){
        char s[2];
        cin>>s;
        if(s[0]=='P'){
            one=1;
        }else if(s[0]=='W'){
            two=1;
        }else if(s[0]=='G'){
            thr=1;
        }else{
            fou=1;
        }
    }
    if(one+two+thr+fou==3){
        cout<<"Three"<<endl;
    }else{
        cout<<"Four"<<endl;
    }
    return 0;
}