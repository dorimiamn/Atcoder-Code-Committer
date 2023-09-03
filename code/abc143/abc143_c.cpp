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
    string S;
    cin>>N>>S;
    for(int i=1;i<N-1;i++){
        if(S[i]==S[i-1]){
            S.erase(S.begin()+i-1);
            i--;
            N--;
        }
        if(S[i]==S[i+1]){
            S.erase(S.begin()+i+1);
            i--;
            N--;
        }
    }
    cout<<S.length()<<endl;
    return 0;
}

//a=97,z=122