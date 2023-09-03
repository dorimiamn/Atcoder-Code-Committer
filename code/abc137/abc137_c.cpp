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
    int N;
    ll count=0;
    cin>>N;
    unordered_map<string,int> mp;
    for(int i=0;i<N;i++){
        string A;
        cin>>A;
        sort(A.begin(),A.end());
        count+=mp[A];
        mp[A]++;
    }
    cout<<count<<endl;
    return 0;
}

//a=97,z=122