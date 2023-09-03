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
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
        if(i*j==N){
            cout<<"Yes"<<endl;
            return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
//a=97,z=122