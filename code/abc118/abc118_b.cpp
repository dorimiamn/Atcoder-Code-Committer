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
#include <wchar.h>

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,M,K,count=0;
    cin>>N>>M;
    map<int,int> A;
    rep(i,N){
        cin>>K;
        rep(j,K){
            int num;
            cin>>num;
            A[num]++;
        }
    }
    for(auto x:A){
        if(x.second==N){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}

//a=97,z=122