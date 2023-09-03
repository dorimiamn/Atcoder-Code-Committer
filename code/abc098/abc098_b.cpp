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
    int N,MAX=0;
    string S;
    cin>>N>>S;
    rep(i,N-1){
        int d[30],count=0;
        memset(d,0,sizeof(d));
        rep(j,i+1){
            int a=int(S[j]);
            d[a-97]=1;
        }
        for(int j=i+1;j<N;j++){
            int b=int(S[j]);
            if(d[b-97]==1){
                count++;
                d[b-97]=-1;
            }
        }
        MAX=max(MAX,count);
    }
    cout<<MAX<<endl;
    return 0;
}