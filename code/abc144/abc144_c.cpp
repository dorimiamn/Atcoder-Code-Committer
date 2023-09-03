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
    ll N,min=INF*10000;
    cin>>N;
    for(ll i=1;i<=sqrt(N);i++){
        if(N%i==0){
            ll a=N/i;
            ll b=i;
            if(min>a+b-2){
                min=a+b-2;
            }
        }
    }
    cout<<min<<endl;
    return 0;
}

//a=97,z=122

//6,15の時