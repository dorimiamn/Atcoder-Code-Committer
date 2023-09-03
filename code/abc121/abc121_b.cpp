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

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,M,C,count=0;
    cin >>N>>M>>C;
    int B[M];
    int A[N][M];
    for(int i=0;i<M;i++){
        cin>>B[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }
    rep(i,N){
        int sum=C;
        rep(j,M){
            sum+=A[i][j]*B[j];
        }
        if(sum>0) count++;
    }
    cout<<count<<endl;
    return 0;
}