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
    ll A,B,C,D;
    ll count=0;
    cin>>A>>B>>C>>D;
    A--;
    if(C<D){
        ll r=D;
        D=C;
        C=r;
    }
    ll g=1,c=C,d=D;
    while(g!=0){
        g=c%d;
        c=d;
        d=g;
    }
    g=c;
    ll l=(C*D)/g;
    ll sumB=B-(B/C+B/D)+(B/l);
    ll sumA=A-(A/C+A/D)+(A/l);
    cout<<sumB-sumA<<endl;
    return 0;
}