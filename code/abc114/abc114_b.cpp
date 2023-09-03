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
    string S;
    cin>>S;
    int A[S.length()],min=99999999,leng=S.length();
    rep(i,leng){
        A[i]=stoi(S.substr(i,1));
    }
    rep(i,leng-2){
        int b=A[i]*100+A[i+1]*10+A[i+2];
        int a=abs(753-b);
        if(min>a) min=a;
    }
    cout<<min<<endl<<endl;
    return 0;
}

//a=97,z=122