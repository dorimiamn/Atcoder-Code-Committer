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
    int a=INF;
    rep(i,4){
       int x;
      cin>>x;
      a=min(a,x);
    }
  cout<<a<<endl;
    return 0;
}
 
//a=97,z=122
