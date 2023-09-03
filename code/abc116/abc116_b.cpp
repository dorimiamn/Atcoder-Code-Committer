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
    int s,i=1,a[1000001];
    memset(a,0,sizeof a);
    cin>>s;
    a[s]=1;
    while(1){
        i++;
        if(s%2==1){
            s=3*s+1;
        }else{
            s/=2;
        }
        if(a[s]!=0){
            cout<<i<<endl;
            return 0;
        }
        a[s]=i;
    }
    return 0;
}

//a=97,z=122