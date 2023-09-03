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
    double sum;
    int N;
    double a;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>S;
        if(S=="BTC"){
            sum+=a*380000;
        }else{
            sum+=a;
        }
    }
    cout<<setprecision(20)<<sum<<endl;
    return 0;
}