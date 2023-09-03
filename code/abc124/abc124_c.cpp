#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll INF=1e13+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string S;
    cin>>S;
    int L=S.length(),countA=0,countB=0;
    for(int i=0;i<L;i++){
        if(i%2==0){
            if(S[i]=='0')countA++;
        }else{
            if(S[i]=='1')countA++;
        }
    }
    for(int i=0;i<L;i++){
        if(i%2==0){
            if(S[i]=='1')countB++;
        }else{
            if(S[i]=='0')countB++;
        }
    }
    cout<<min(countA,countB)<<endl;
    return 0;
}

//a=97,z=122