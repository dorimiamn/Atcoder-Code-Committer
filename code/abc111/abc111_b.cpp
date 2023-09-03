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
    int N,min=10000;
    cin>>N;
    string S(3,'1');
    rep(i,10){
        int check=stoi(S);
        if(check>=N){
            cout<<check<<endl;
            return 0;
        }
        S[0]++;
        S[1]++;
        S[2]++;
    }
    return 0;
}

//a=97,z=122