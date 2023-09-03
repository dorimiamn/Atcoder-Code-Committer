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
    ll A,B,num=2;
    cin>>A>>B;
    if(A<B){
        ll a=A;
        A=B;
        B=a;
    }
    ll GCD;
    GCD=A%B;
    while(GCD>0){
        A=B;
        B=GCD;
        GCD=A%B;
    }
    GCD=B;
    ll lis[999999];
    ll count=1;
    lis[0]=1;
    ll check=sqrt(A)+sqrt(B);
    while(num<=check&&GCD!=1){
        if(GCD % num == 0){
            count++;
            while(GCD % num == 0){
                GCD /= num;
            }
        }
        num++;
    }
    if(GCD!=1)count++;
    cout<<count<<endl;
    return 0;
}

//参考にさせていただいたコードhttps://atcoder.jp/contests/abc142/submissions/7789711