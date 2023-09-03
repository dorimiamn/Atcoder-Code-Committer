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
    int L[N];
    rep(i,N)cin>>L[i];
    sort(L,L+N);
    int MAX=L[N-1];
    L[N-1]=0;
    int sum=accumulate(L,L+N,0);
    if(MAX<sum) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

//a=97,z=122