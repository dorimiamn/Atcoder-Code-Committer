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
    vector<string> S(110);
    string O;
    map<string,int> A;
    cin>>N;
    rep(i,N)cin>>S[i];
    A[S[0]]++;
    O=S[0];
    for(int i=1;i<N;i++){
        string a=S[i];
        if(A[a]!=1&&a.front()==O.back()){
            A[a]++;
            O=a;
        }else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}

//a=97,z=122