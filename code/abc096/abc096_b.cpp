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
    int a,K;
    ll sum=0;
    priority_queue<int> ABC;
    rep(i,3){
        cin>>a;
        ABC.push(a);
    }
    cin>>K;
    rep(i,K){
        a=ABC.top()*2;
        ABC.pop();
        ABC.push(a);
    }
    rep(i,3){
        sum+=ABC.top();
        ABC.pop();
    }
    cout<<sum<<endl;
    return 0;
}

//a=97,z=122